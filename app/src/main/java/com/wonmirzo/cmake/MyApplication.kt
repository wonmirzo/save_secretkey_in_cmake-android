package com.wonmirzo.cmake

import android.app.Application
import android.util.Log

class MyApplication : Application() {
    private val TAG = MyApplication::class.java.simpleName

    init {
        System.loadLibrary("native-lib")
    }

    external fun getKeyFromCMake(i: Int): String?

    override fun onCreate() {
        super.onCreate()

        val privateKey = getKeyFromCMake(1)
        val publicKey = getKeyFromCMake(2)

        Log.d(TAG, "Private Key : $privateKey")
        Log.d(TAG, "Public Key : $publicKey")
    }
}