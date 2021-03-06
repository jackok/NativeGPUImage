//
// Created by ben622 on 2019/9/25.
// Android通过该接口进行gl交互
//

#ifndef NATIVEGPUIMAGE_ANDROID_GL_BRIDGE_HPP
#define NATIVEGPUIMAGE_ANDROID_GL_BRIDGE_HPP

#include "../include/jni/JniHelpers.h"
#include "android_native_filter.hpp"
#include "../filter/gpu_image_gaussian_blur_filter.hpp"
#include "../filter/gpu_image_pixelation_filter.hpp"
#include "../filter/gpu_image_dilation_filter.hpp"
#include "../filter/gpu_image_zoom_blur_filter.hpp"
#include "../filter/gpu_image_white_balance_filter.hpp"
#include "../filter/gpu_image_3x3_texture_sampling_filter.hpp"
#include "../filter/gpu_image_weak_pixel_inclusion_filter.hpp"
#include "../filter/gpu_image_vignette_filter.hpp"
#include "../filter/gpu_image_vibrance_filter.hpp"
#include "../filter/gpu_image_add_blend_filter.hpp"
#include "../filter/gpu_image_toon_filter.hpp"
#include "../filter/gpu_image_gamma_filter.hpp"
#include "../filter/gpu_image_false_color_filter.hpp"
#include "../filter/gpu_image_exposure_filter.hpp"
#include "../filter/gpu_image_exclusion_blend_filter.hpp"
#include "../filter/gpu_image_3x3_convolution_filter.hpp"
#include "../filter/gpu_image_emboss_filter.hpp"
#include "../filter/gpu_image_divide_blend_filter.hpp"
#include "../filter/gpu_image_mix_blend_filter.hpp"
#include "../filter/gpu_image_alpha_blend_filter.hpp"
#include "../filter/gpu_image_dissolve_blend_filter.hpp"
#include "../filter/gpu_image_directional_sobel_edge_detection_filter.hpp"
#include "../filter/gpu_image_grayscale_filter.hpp"
#include "../filter/gpu_image_sobel_edge_detection_filter.hpp"
#include "../filter/gpu_image_saturation_filter.hpp"
#include "../filter/gpu_image_contrast_filter.hpp"
#include "../filter/gpu_image_brightness_filter.hpp"
#include "../filter/gpu_image_levels_filter.hpp"
#include "../filter/gpu_image_rgb_filter.hpp"
#include "../filter/gpu_image_rgb_dilation_filter.hpp"
#include "../filter/gpu_image_hue_filter.hpp"
#include "../filter/gpu_image_monochrome_filter.hpp"
#include "../filter/gpu_image_sharpen_filter.hpp"
#include "../filter/gpu_image_highlight_shadow_filter.hpp"
#include "../filter/gpu_image_haze_filter.hpp"
#include "../filter/gpu_image_solarize_filter.hpp"
#include "../filter/gpu_image_luminance_filter.hpp"
#include "../filter/gpu_image_luminance_threshold_filter.hpp"
#include "../filter/gpu_image_halftone_filter.hpp"
#include "../filter/gpu_image_crosshatch_filter.hpp"
#include "../filter/gpu_image_sobel_threshold_filter.hpp"
#include "../filter/gpu_image_threshold_edge_detection_filter.hpp"
#include "../filter/gpu_image_sketch_filter.hpp"


using namespace ben::jni;
namespace ben {
    namespace ngp {
        class NGPNativeBridge : public JavaClass {
        public:
            NGPNativeBridge(JNIEnv *env);

            virtual void initialize(JNIEnv *env);

            virtual void mapFields();

            virtual const char *getCanonicalName() const;

        private:
            static void nativeApplyFilter(JNIEnv *env, jclass javaThis, jobject object);

            static void nativeApplyBitmap(JNIEnv *env, jclass javaThis, jobject object);

            static void nativeRequestRender(JNIEnv *env, jclass javaThis);

            static void nativeCapture(JNIEnv *env, jclass javaThis, jobject object);

            static void nativeSurfaceCreated(JNIEnv *env, jclass javaThis, jobject surface);

            static void nativeSurfaceChanged(JNIEnv *env, jclass javaThis, jint width, jint height);

            static void nativeDestroyed(JNIEnv *env, jclass javaThis);

            static void nativeDestorySurfaceGL(JNIEnv *env, jclass javaThis);

            static void nativeCreateGL(JNIEnv *env, jclass javaThis);

            static void nativeApplyRotation(JNIEnv *env, jclass javaThis, jint rotation, jboolean flipHorizontal, jboolean flipVertical);

            static void nativeApplyScaleType(JNIEnv *env, jclass javaThis, jint scaleType);

            static void nativeApplyYUV420(JNIEnv *env, jclass javaThis, jbyteArray jbyte, jint width, jint height);


        private:
            static void readBitmapPixel(JNIEnv *env, GPUImageTwoInputFilter *filter);

        };
    }
}

#endif //NATIVEGPUIMAGE_ANDROID_GL_BRIDGE_HPP
