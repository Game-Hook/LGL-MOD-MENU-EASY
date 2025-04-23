
//  فقط لنسخ 32 bit

/* Variables for hook offset method */
/* هوك المتعلق بالوفست */
//hook_name = bool mod = false;
//hook_name_fake_func || اي اسم بالك
//hook_name_point_func || اي اسم بالك بس كون يختلف عن اسم الاول
//edit_Bool || قيمة تعديل (true or false)

// BOOL Hook
#define ADD_BOOL_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Bool) \
bool (*hook_name_point_func)(void *instance); \
bool hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Bool; \
        } \
    } \
    return hook_name_point_func(instance); \
}



// FLOAT Hook
/* Float type: */
#define ADD_FLOAT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Float) \
float (*hook_name_point_func)(void *instance); \
float hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Float; \
        } \
    } \
    return hook_name_point_func(instance); \
}


// DOUBLE Hook
/* Double type: */
#define CREATE_DOUBLE_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Double) \
double (*hook_name_point_func)(void *instance); \
double hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Double; \
        } \
    } \
    return hook_name_point_func(instance); \
}



// INT Hook
/* Interger type: */
#define CREATE_INT_HOOK(hook_name, hook_name_point_func, hook_name_fake_func, edit_Int) \
int (*hook_name_point_func)(void *instance); \
int hook_name_fake_func(void *instance) { \
    if (instance != NULL) { \
        if (hook_name) { \
            return edit_Int; \
        } \
    } \
    return hook_name_point_func(instance); \
}

//كملنا من جميع الدوال التي تعمل مع اوفسيت
























