#include <jni.h>
#include <iostream>
#include "validatorLib_ValidatorLib.h"

class Validator {
public:
    Validator() {
        std::cout << "Validator Created!" << std::endl;
    }

    bool validate() {
        std::cout << "Validation in progress..." << std::endl;
        return true; // Example validation logic (return false to simulate failure)
    }
};

// Implement createValidator
extern "C"
JNIEXPORT jlong JNICALL Java_validatorLib_ValidatorLib_createValidator(JNIEnv* env, jobject obj) {
    return (jlong) new Validator();
}

// Implement destroyValidator
extern "C"
JNIEXPORT void JNICALL Java_validatorLib_ValidatorLib_destroyValidator(JNIEnv* env, jobject obj, jlong validatorPtr) {
    delete (Validator*)validatorPtr;
}

// Implement validate
extern "C"
JNIEXPORT jboolean JNICALL Java_validatorLib_ValidatorLib_validate(JNIEnv* env, jobject obj, jlong validatorPtr) {
    Validator* validator = (Validator*)validatorPtr;
    return validator->validate() ? JNI_TRUE : JNI_FALSE;
}
