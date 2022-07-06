#include <jni.h>
#include <string>

std::string getData(int x) {
    std::string app_secret = "Null";

    if (x == 1)
        app_secret = "Hey man we're gonna jump on that spaceship and get out here wanna come"; //The first key that you want to protect against decompilation
    if (x == 2)
        app_secret = "simple dimple";   //The second key that you want to protect against decompilation

    // The number of parameters to be protected can be increased.

    return app_secret;
}

extern "C" jstring
Java_com_wonmirzo_cmake_MyApplication_getKeyFromCMake(
        JNIEnv *env,
        jobject /* this */,
        jint id) {
    std::string app_secret = "Null";
    app_secret = getData(id);
    return env->NewStringUTF(app_secret.c_str());
}