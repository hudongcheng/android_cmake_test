#include <jni.h>
#include <string>
//#include <android/bitmap.h>

//#include "my-add.h"
//#include "import-lib.h"
#include "add1.h"

extern "C"
jstring
Java_com_example_hdc_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    char str[64] = {0};
    //std::string hello = "Hello from C++ ";
    int a = 0;//myAdd(1, 2) + mysub(5, 2);
    int b = add1(2, 2);
    snprintf(str, 64, "Hello from C++, a = %d, b = %d", a, b);
    return env->NewStringUTF(str);
}


