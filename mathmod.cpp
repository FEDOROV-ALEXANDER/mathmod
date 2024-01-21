//#include <stdio.h>
//#include <stdlib.h>
//
//struct AppendableArray
//{
//    int* array;
//    int current_length; // РєРѕР»РёС‡РµСЃС‚РІРѕ СЌР»РµРјРµРЅРµС‚РѕРІ, РєРѕС‚РѕСЂС‹Рµ РјС‹ Р·Р°РїРѕР»РЅРёР»Рё
//    int max_capacity; // РјР°РєСЃРёРјР°Р»СЊРЅРѕРµ РєРѕР»РёС‡РµСЃС‚РІРѕ СЌР»РµРјРµРЅС‚РѕРІ, РєРѕС‚РѕСЂРѕРµ РјС‹ РјРѕР¶РµРј Р·Р°РїРѕР»РЅРёС‚СЊ
//};
//
//
//void init_appendable_array(AppendableArray* aarray) {
//    aarray->max_capacity = 10;
//    aarray->current_length = 0;
//    aarray->array = new int[aarray->max_capacity];
//}
//
//
//void print_appendable_array(const AppendableArray* aarray) {
//    for (int i = 0; i < aarray->current_length; i++) {
//        printf("%i\n", aarray->array[i]);
//    }
//    printf("len: %i max_cap: %i\n", aarray->current_length, aarray->max_capacity);
//}
//
//
//void add_appendable_array(AppendableArray* aarray, int value) {
//    if (aarray->current_length == aarray->max_capacity) {
//        int* new_array = new int[aarray->max_capacity * 2];
//        for (int i = 0; i < aarray->current_length; i++) {
//            new_array[i] = aarray->array[i];
//        }
//        delete[] aarray->array;
//        aarray->array = new_array;
//        aarray->max_capacity *= 2;
//    }
//
//    aarray->array[aarray->current_length++] = value;
//}
//
//
//void delete_appendable_array(AppendableArray* aarray) {
//    delete[] aarray->array;
//}
//
//
//int main() {
//    AppendableArray my_array;
//    init_appendable_array(&my_array);
//    print_appendable_array(&my_array);
//
//    for (int i = 0; i < 100000000; i++) {
//        add_appendable_array(&my_array, rand());
//    }
//
//    print_appendable_array(&my_array);
//    delete_appendable_array(&my_array);
//    return 0;
//}