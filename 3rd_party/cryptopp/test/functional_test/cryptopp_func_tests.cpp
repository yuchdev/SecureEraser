#include <iostream>
#include <string>
#include <vector>

#include "cryptlib.h"
#include "files.h"
#include "osrng.h"
#include "filters.h"
#include "dsa.h"
#include "assert.h"

using std::cout;
using std::cerr;
using std::endl;

using std::string;
using std::vector;

using CryptoPP::AutoSeededRandomPool;
using CryptoPP::Exception;
using CryptoPP::FileSink;
using CryptoPP::FileSource;
using CryptoPP::ArraySink;
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::StringStore;
using CryptoPP::Redirector;
using CryptoPP::SignerFilter;
using CryptoPP::SignatureVerificationFilter;
using CryptoPP::DSA;


#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

// Functional tests
/*
*/

bool VerifyMessageNoThrow(const DSA::PublicKey& PublicKey,
    const string& message, const string& signature)
{
    DSA::Verifier verifier(PublicKey);

    bool result = false;
    StringSource(message + signature, true,
        new SignatureVerificationFilter(
            verifier,
            new ArraySink((byte*)&result, sizeof(result)),
            SignatureVerificationFilter::PUT_RESULT
            )
        );
    return result;
}


// ActivationCode = DSA(HWID+ActivationKey, PrivateKey)
void DSA_compose(const string& hwid_key, const vector<byte>& privateKeyArray, vector<byte>& activationCodeArray)
{
    AutoSeededRandomPool rng;

    DSA::PrivateKey PrivateKey;
    PrivateKey.Load(StringSource(&privateKeyArray[0], privateKeyArray.size(), true).Ref());

    DSA::Signer signer(PrivateKey);
    string activation_code;
    StringSource(hwid_key, true, new SignerFilter(rng, signer, new StringSink(activation_code)));
    activationCodeArray.assign(activation_code.begin(), activation_code.end());
}

// IsChecked = DSA_Check(ActivationCode, PublicKey)
bool DSA_check(const string& message, const vector<byte>& publicKey, const vector<byte>& activationCode)
{
    string activationCodeString(activationCode.begin(), activationCode.end());
    DSA::PublicKey PublicKey;
    PublicKey.Load(StringSource(&publicKey[0], publicKey.size(), true).Ref());

    return VerifyMessageNoThrow(PublicKey, message, activationCodeString);
}

void GenerateKeys(vector<byte>& publicKey, vector<byte>& privateKey)
{
    AutoSeededRandomPool* rng = new AutoSeededRandomPool;

    // Generate Private Key
    DSA::PrivateKey* PrivateKey = new DSA::PrivateKey;
    PrivateKey->GenerateRandomWithKeySize(*rng, 1024);
    if (!PrivateKey->Validate(*rng, 3))
    {
        throw("DSA key generation failed");
    }
    byte privateKeyArray[512] = {};
    ArraySink privateKeySink(privateKeyArray, 512);
    PrivateKey->Save(privateKeySink.Ref());
    size_t createdPrivateLength = privateKeySink.TotalPutLength();

    // Generate Public Key   
    byte publicKeyArray[512] = {};
    DSA::PublicKey* PublicKey = new DSA::PublicKey;
    PublicKey->AssignFrom(*PrivateKey);
    ArraySink publicKeySink(publicKeyArray, 512);
    PublicKey->Save(publicKeySink.Ref());
    size_t createdPublicLength = publicKeySink.TotalPutLength();

    privateKey.assign(privateKeyArray, privateKeyArray + createdPrivateLength);
    publicKey.assign(publicKeyArray, publicKeyArray + createdPublicLength);

    delete rng;
    delete PrivateKey;
    delete PublicKey;
}

BOOST_AUTO_TEST_SUITE(CryptoPPFunctionalTests);

BOOST_AUTO_TEST_CASE(DSA_Check_Test)
{
    string hwid_key = "3424307880131970169159181858827012313841690b9869b359cb082e34fg";

    try
    {
        vector<byte> publicKey;
        vector<byte> privateKey;
        vector<byte> activationCode;

        GenerateKeys(publicKey, privateKey);
        DSA_compose(hwid_key, privateKey, activationCode);
        bool dsa_correct = DSA_check(hwid_key, publicKey, activationCode);
        BOOST_CHECK_EQUAL(dsa_correct, true);
    }
    catch (CryptoPP::Exception& e)
    {
        cerr << "caught Exception..." << endl;
        cerr << e.what() << endl;
        // error anyway
        BOOST_CHECK_EQUAL(true, false);
    }
}

BOOST_AUTO_TEST_SUITE_END()