// فقط لنسخ 32 بت و 64 بت
// For 32-bit and 64-bit systems

/* ========================================================================
   متغيرات وتعريفات الهوك (Hook Macros and Variables)
   ========================================================================

   - hook_name: متغير من نوع bool لتفعيل أو تعطيل الهوك
   - hook_name: Boolean variable to enable or disable the hook

   - hook_name_fake_func: اسم الدالة الوهمية التي ترجع القيمة المعدلة
   - hook_name_fake_func: The name of the fake function that returns the modified value

   - hook_name_point_func: مؤشر إلى الدالة الأصلية لحفظ القيمة قبل التعديل
   - hook_name_point_func: Pointer to the original function to save the value before modification

   - edit_Bool: قيمة منطقية (مثال: true أو false)
   - edit_Bool: Boolean value (example: true or false)

   - edit_Float: قيمة عشرية (مثال: 9999)
   - edit_Float: Float value (example: 9999)

   - edit_Int: قيمة عدد صحيح (مثال: 9999)
   - edit_Int: Integer value (example: 9999)

   - edit_Double: قيمة عشرية بدقة عالية (مثال: 9999)
   - edit_Double: Double value (example: 9999)
*/

/* ========================================================================
   هوكات ترجع قيمة (دوال الإرجاع)
   HOOKS WITH RETURN VALUE
   ======================================================================== */

// هوك للمتغيرات المنطقية (bool)
// Hook for Boolean variables (bool)
#define ADD_BOOL_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool) \
    bool (*hook_name_point_func)(void *instance); \
    bool hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                return (edit_Bool); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك للأرقام العشرية (float)
// Hook for floating-point variables (float)
#define ADD_FLOAT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float) \
    float (*hook_name_point_func)(void *instance); \
    float hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                return (float)(edit_Float); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك للأرقام العشرية بدقة عالية (double)
// Hook for double-precision floating-point variables (double)
#define ADD_DOUBLE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double) \
    double (*hook_name_point_func)(void *instance); \
    double hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                return (double)(edit_Double); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك للأعداد الصحيحة (int)
// Hook for integer variables (int)
#define ADD_INT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int) \
    int (*hook_name_point_func)(void *instance); \
    int hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                return (int)(edit_Int); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

/* ========================================================================
   هوكات مع تعديل الأوفست (32 بت)
   HOOKS WITH OFFSET UPDATE - 32-bit
   ======================================================================== */

// هوك مع أوفست للمتغيرات المنطقية (bool) على 32 بت
// Hook with offset for Boolean variables (bool) on 32-bit
#define ADD_BOOL_UPDATE_HOOK_32(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Bool) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(bool *) ((uint32_t) instance + offsetFOR) = (edit_Bool); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأرقام العشرية (float) على 32 بت
// Hook with offset for floating-point variables (float) on 32-bit
#define ADD_FLOAT_UPDATE_HOOK_32(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(float *) ((uint32_t) instance + offsetFOR) = (float)(edit_Float); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأرقام العشرية بدقة عالية (double) على 32 بت
// Hook with offset for double-precision variables (double) on 32-bit
#define ADD_DOUBLE_UPDATE_HOOK_32(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Double) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(double *) ((uint32_t) instance + offsetFOR) = (double)(edit_Double); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأعداد الصحيحة (int) على 32 بت
// Hook with offset for integer variables (int) on 32-bit
#define ADD_INT_UPDATE_HOOK_32(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Int) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(int *) ((uint32_t) instance + offsetFOR) = (int)(edit_Int); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

/* ========================================================================
   هوكات مع تعديل الأوفست (64 بت)
   HOOKS WITH OFFSET UPDATE - 64-bit
   ======================================================================== */

// هوك مع أوفست للمتغيرات المنطقية (bool) على 64 بت
// Hook with offset for Boolean variables (bool) on 64-bit
#define ADD_BOOL_UPDATE_HOOK_64(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Bool) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(bool *) ((uint64_t) instance + offsetFOR) = (edit_Bool); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأرقام العشرية (float) على 64 بت
// Hook with offset for floating-point variables (float) on 64-bit
#define ADD_FLOAT_UPDATE_HOOK_64(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Float) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(float *) ((uint64_t) instance + offsetFOR) = (float)(edit_Float); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأرقام العشرية بدقة عالية (double) على 64 بت
// Hook with offset for double-precision variables (double) on 64-bit
#define ADD_DOUBLE_UPDATE_HOOK_64(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Double) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(double *) ((uint64_t) instance + offsetFOR) = (double)(edit_Double); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك مع أوفست للأعداد الصحيحة (int) على 64 بت
// Hook with offset for integer variables (int) on 64-bit
#define ADD_INT_UPDATE_HOOK_64(hook_name, hook_name_point_func, hook_name_fake_func, offsetFOR, edit_Int) \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                *(int *) ((uint64_t) instance + offsetFOR) = (int)(edit_Int); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

/* ========================================================================
   هوكات للدوال من نوع void (بدون تعديل مباشر)
   HOOKS FOR VOID FUNCTIONS (NO UPDATE)
   ======================================================================== */

// هوك لدوال void مع متغير bool
// Hook for void functions with bool variable
#define ADD_BOOL_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool) \
    void (*hook_name_point_func)(void *instance, bool value); \
    void hook_name_fake_func(void *instance, bool value) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func(instance, (edit_Bool)); \
                return; \
            } \
        } \
        hook_name_point_func(instance, value); \
    }

// هوك لدوال void مع متغير float
// Hook for void functions with float variable
#define ADD_FLOAT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float) \
    void (*hook_name_point_func)(void *instance, float value); \
    void hook_name_fake_func(void *instance, float value) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func(instance, (float)(edit_Float)); \
                return; \
            } \
        } \
        hook_name_point_func(instance, value); \
    }

// هوك لدوال void مع متغير double
// Hook for void functions with double variable
#define ADD_DOUBLE_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double) \
    void (*hook_name_point_func)(void *instance, double value); \
    void hook_name_fake_func(void *instance, double value) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func(instance, (double)(edit_Double)); \
                return; \
            } \
        } \
        hook_name_point_func(instance, value); \
    }

// هوك لدوال void مع متغير int
// Hook for void functions with int variable
#define ADD_INT_VOID_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int) \
    void (*hook_name_point_func)(void *instance, int value); \
    void hook_name_fake_func(void *instance, int value) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func(instance, (int)(edit_Int)); \
                return; \
            } \
        } \
        hook_name_point_func(instance, value); \
    }

/* ========================================================================
   هوكات للدوال من نوع void مع تعديل مباشر
   HOOKS FOR VOID FUNCTIONS WITH UPDATE
   ======================================================================== */

// هوك لدوال void مع متغير bool وتعديل مباشر
// Hook for void functions with bool variable and update
#define ADD_BOOL_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Bool) \
    void (*hook_name_point_func2)(void *instance, bool value); \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func2(instance, (edit_Bool)); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك لدوال void مع متغير float وتعديل مباشر
// Hook for void functions with float variable and update
#define ADD_FLOAT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Float) \
    void (*hook_name_point_func2)(void *instance, float value); \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func2(instance, (float)(edit_Float)); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك لدوال void مع متغير double وتعديل مباشر
// Hook for void functions with double variable and update
#define ADD_DOUBLE_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Double) \
    void (*hook_name_point_func2)(void *instance, double value); \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func2(instance, (double)(edit_Double)); \
            } \
        } \
        return hook_name_point_func(instance); \
    }

// هوك لدوال void مع متغير int وتعديل مباشر
// Hook for void functions with int variable and update
#define ADD_INT_VOID_UPDATE_HOOK(hook_name, hook_name_point_func, hook_name_point_func2, hook_name_fake_func, edit_Int) \
    void (*hook_name_point_func2)(void *instance, int value); \
    void (*hook_name_point_func)(void *instance); \
    void hook_name_fake_func(void *instance) { \
        if (instance != NULL) { \
            if (hook_name) { \
                hook_name_point_func2(instance, (int)(edit_Int)); \
            } \
        } \
        return hook_name_point_func(instance); \
    }
