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


/**
 * this method is used to show how to travase the array
 * @param env
 * @param instance
 * @param intarray_
 * @return
 */
JNIEXPORT jint JNICALL
Java_com_hw_liuxiao_testjni_TestJni_gray(JNIEnv *env, jobject instance, jintArray intarray_) {
    jint *intarray = (*env)->GetIntArrayElements(env, intarray_, NULL);

    int size = (*env)->GetArrayLength(env,intarray_);
    int i = 0;
    for(i = 0;i < size;i++){
        __android_log_print(ANDROID_LOG_INFO,"FromJNI","this is from gray %d",*(intarray+i));
    }

    /*
     * show to us how to access class field  and object field
     */
    jfieldID fid;
    jmethodID mid;
    jclass clz;
    clz = (*env)->GetObjectClass(env,instance);     //get object class by params obj
    fid = (*env)->GetStaticFieldID(env,clz,"version","I");    //get fieldid by signature and filed name
    __android_log_print(ANDROID_LOG_INFO,"FromJNI","fid version from jni is: %d",fid);
    int version  = (*env)->GetStaticIntField(env,clz,fid);  //class field

    __android_log_print(ANDROID_LOG_INFO,"FromJNI","version from jni is: %d",version);


    fid = (*env)->GetFieldID(env,clz,"name","Ljava/lang/String;");       //object field
    __android_log_print(ANDROID_LOG_INFO,"FromJNI","fid name from jni is: %d",fid);
    jstring name =  (jstring)((*env)->GetObjectField(env,instance,fid));
    const char *str = (*env)->GetStringUTFChars(env, name, 0);

    __android_log_print(ANDROID_LOG_INFO,"FromJNI","name from jni is: %s",str);

    (*env)->ReleaseIntArrayElements(env, intarray_, intarray, 0);
}