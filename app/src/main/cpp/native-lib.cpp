#include <jni.h>
#include <string>
#include <android/bitmap.h>

#include "my-add.h"
#include "import-lib.h"

extern "C"
jstring
Java_com_example_hdc_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++ ";
    int a = myAdd(1, 2) + mysub(5, 2);
    AndroidBitmapInfo bmpInfo = {0};
    jobject  bmpObj;
    AndroidBitmap_getInfo(env, bmpObj, &bmpInfo);
    return env->NewStringUTF(hello.c_str());
}


