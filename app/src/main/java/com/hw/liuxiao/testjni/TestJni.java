package com.hw.liuxiao.testjni;

import android.util.Log;

/**
 * Created by Liuxiao on 2017/12/25 0025.
 */

public class TestJni {
    public static final String TAG ="TESTJNI";
    static {

        System.loadLibrary("bitmapprocess");
    }



    public TestJni(String name){
        this.name = name;
    }

    public TestJni(){

    }


    public String name = "liuxiao";
    public static int version =  12;

    public native int add(int a,int b);
    public native int sub(int a,int b);

    public native int gray(int[] intarray);



    public void printInfo(){
        Log.i(TAG,"name is " +name+"  version is :"+version);
    }


    public static void sayHello(){
        Log.i(TAG,"welcome to  TestJni");
    }



}
