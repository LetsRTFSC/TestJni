//
// Created by Liuxiao on 2017/12/20 0020.
//

#include "../../../distribution/include/add.h"

#include <jni.h>
#include <Android/log.h>
JNIEXPORT jint JNICALL
Java_com_hw_liuxiao_testjni_TestJni_add(JNIEnv *env, jobject instance, jint a, jint b) {

    // TODO
    __android_log_print(ANDROID_LOG_ERROR,"FromJNI","this is from JNI by native method");
    return wrap_add(a,b);
}

int wrap_add(int a,int b)
{

    __android_log_print(ANDROID_LOG_INFO,"FromJNI","this is from JNI by wrap_add %d",a+b);
    return add(a,b);
}

JNIEXPORT jint JNICALL
Java_com_hw_liuxiao_testjni_TestJni_sub(JNIEnv *env, jobject instance, jint a, jint b) {

    // TODO

}