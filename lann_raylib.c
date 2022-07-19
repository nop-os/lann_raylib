#include <raylib.h>
#include <stddef.h>
#include <stdio.h>
#include <lann.h>

static ln_uint_t lann_rl_InitWindow(void) {
  if (LN_VALUE_TYPE(ln_get_arg(0)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(1)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(2)) != ln_type_pointer) {
    return LN_INVALID_TYPE;
  }
  
  if (!ln_check_string(LN_VALUE_TO_PTR(ln_get_arg(2)))) {
    return LN_OUT_OF_BOUNDS;
  }
  
  InitWindow(LN_VALUE_TO_INT(ln_get_arg(0)), LN_VALUE_TO_INT(ln_get_arg(1)), (const char *)(ln_data + LN_VALUE_TO_PTR(ln_get_arg(2))));
  return LN_NULL;
}

static ln_uint_t lann_rl_WindowShouldClose(void) {
  return LN_INT_TO_VALUE(WindowShouldClose());
}

static ln_uint_t lann_rl_CloseWindow(void) {
  CloseWindow();
  return LN_NULL;
}

static ln_uint_t lann_rl_ClearBackground(void) {
  if (LN_VALUE_TYPE(ln_get_arg(0)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(1)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(2)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(3)) != ln_type_number) {
    return LN_INVALID_TYPE;
  }
  
  ClearBackground((Color){LN_VALUE_TO_INT(ln_get_arg(0)), LN_VALUE_TO_INT(ln_get_arg(1)), LN_VALUE_TO_INT(ln_get_arg(2)), LN_VALUE_TO_INT(ln_get_arg(3))});
  return LN_NULL;
}

static ln_uint_t lann_rl_BeginDrawing(void) {
  BeginDrawing();
  return LN_NULL;
}

static ln_uint_t lann_rl_EndDrawing(void) {
  EndDrawing();
  return LN_NULL;
}

static ln_uint_t lann_rl_DrawPixel(void) {
  if (LN_VALUE_TYPE(ln_get_arg(0)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(1)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(2)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(3)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(4)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(5)) != ln_type_number) {
    return LN_INVALID_TYPE;
  }
  
  Color color = (Color){LN_VALUE_TO_INT(ln_get_arg(2)), LN_VALUE_TO_INT(ln_get_arg(3)), LN_VALUE_TO_INT(ln_get_arg(4)), LN_VALUE_TO_INT(ln_get_arg(5))};
  
  DrawPixel(LN_VALUE_TO_INT(ln_get_arg(0)), LN_VALUE_TO_INT(ln_get_arg(1)), color);
  return LN_NULL;
}

static ln_uint_t lann_rl_DrawLine(void) {
  if (LN_VALUE_TYPE(ln_get_arg(0)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(1)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(2)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(3)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(4)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(5)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(6)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(7)) != ln_type_number) {
    return LN_INVALID_TYPE;
  }
  
  Color color = (Color){LN_VALUE_TO_INT(ln_get_arg(4)), LN_VALUE_TO_INT(ln_get_arg(5)), LN_VALUE_TO_INT(ln_get_arg(6)), LN_VALUE_TO_INT(ln_get_arg(7))};
  
  DrawLine(LN_VALUE_TO_INT(ln_get_arg(0)), LN_VALUE_TO_INT(ln_get_arg(1)), LN_VALUE_TO_INT(ln_get_arg(2)), LN_VALUE_TO_INT(ln_get_arg(3)), color);
  return LN_NULL;
}

static ln_uint_t lann_rl_DrawRectangle(void) {
  if (LN_VALUE_TYPE(ln_get_arg(0)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(1)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(2)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(3)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(4)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(5)) != ln_type_number ||
      LN_VALUE_TYPE(ln_get_arg(6)) != ln_type_number || LN_VALUE_TYPE(ln_get_arg(7)) != ln_type_number) {
    return LN_INVALID_TYPE;
  }
  
  Color color = (Color){LN_VALUE_TO_INT(ln_get_arg(4)), LN_VALUE_TO_INT(ln_get_arg(5)), LN_VALUE_TO_INT(ln_get_arg(6)), LN_VALUE_TO_INT(ln_get_arg(7))};
  
  DrawRectangle(LN_VALUE_TO_INT(ln_get_arg(0)), LN_VALUE_TO_INT(ln_get_arg(1)), LN_VALUE_TO_INT(ln_get_arg(2)), LN_VALUE_TO_INT(ln_get_arg(3)), color);
  return LN_NULL;
}

ln_func_t lann_handles[] = {
  (ln_func_t){0, "rl_InitWindow", lann_rl_InitWindow},
  (ln_func_t){0, "rl_WindowShouldClose", lann_rl_WindowShouldClose},
  (ln_func_t){0, "rl_CloseWindow", lann_rl_CloseWindow},
  (ln_func_t){0, "rl_ClearBackground", lann_rl_ClearBackground},
  (ln_func_t){0, "rl_BeginDrawing", lann_rl_BeginDrawing},
  (ln_func_t){0, "rl_EndDrawing", lann_rl_EndDrawing},
  (ln_func_t){0, "rl_DrawPixel", lann_rl_DrawPixel},
  (ln_func_t){0, "rl_DrawLine", lann_rl_DrawLine},
  (ln_func_t){0, "rl_DrawRectangle", lann_rl_DrawRectangle},
  (ln_func_t){0, NULL, NULL},
};
