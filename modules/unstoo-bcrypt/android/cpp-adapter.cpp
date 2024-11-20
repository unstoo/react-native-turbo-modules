#include <jni.h>
#include "react-native-unstoo-bcrypt.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_unstoobcrypt_UnstooBcryptModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return unstoobcrypt::multiply(a, b);
}
