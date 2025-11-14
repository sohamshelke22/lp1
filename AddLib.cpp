#include <jni.h>
#include "AddNumbers.h"
#include <iostream>
using namespace std;

extern "C" JNIEXPORT jint JNICALL Java_AddNumbers_add(JNIEnv* env, jobject obj, jint a, jint b) {
    cout << "Inside C++ DLL function!" << endl;
    return a + b;
}
