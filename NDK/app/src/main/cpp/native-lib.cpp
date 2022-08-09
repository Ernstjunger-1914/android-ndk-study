#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_vot_ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring prompt,
        jint value
) {
    const char *str = env->GetStringUTFChars(prompt, NULL);
    if (str == NULL) return NULL;

    // char type의 변수에서 사용한 메모리는 함수의 제어를 반환하기 전에 해제
    env->ReleaseStringUTFChars(prompt, str);

    // external fun으로 받은 String과 Int 타입의 데이터를 Logcat에 띄움
    __android_log_print(ANDROID_LOG_INFO, "App Debug", "%s(default %d) : ", str, value);

    const char *buf = "손소독";
    return env->NewStringUTF(buf);
}