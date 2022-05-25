/* =================== rasterize_stroke.h ===================
    Sketch for DeepPen
    By Antonio Priego Raya
    Code created for the DeepPen project:
    https://github.com/AntonioPriego/DeepPen

    Code supported on the magic_wand of Pete Warden
    (https://github.com/petewarden/magic_wand)
============================================================= */

#ifndef TENSORFLOW_LITE_MICRO_EXAMPLES_MAGIC_WAND_RASTERIZE_STROKE_H
#define TENSORFLOW_LITE_MICRO_EXAMPLES_MAGIC_WAND_RASTERIZE_STROKE_H

#include <cstdint>

void RasterizeStroke(
    int8_t* stroke_points,
    int stroke_points_count,
    float x_range, 
    float y_range, 
    int width, 
    int height,
    int8_t* out_buffer);

#endif   // TENSORFLOW_LITE_MICRO_EXAMPLES_MAGIC_WAND_RASTERIZE_STROKE_H
