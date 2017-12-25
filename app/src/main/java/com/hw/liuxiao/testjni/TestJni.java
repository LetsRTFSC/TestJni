package com.hw.liuxiao.testjni;

/**
 * Created by Liuxiao on 2017/12/25 0025.
 */

public class TestJni {
    static {

        System.loadLibrary("bitmapprocess");
    }

    public native int add(int a,int b);
    public native int sub(int a,int b);

}
