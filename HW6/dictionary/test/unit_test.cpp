#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict_contains, set1) {
    // homework
    ArrayDictionary<int, int> hashTable;

    // ensures hasTable is empty
    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_FALSE(hashTable.contain(-1));
    ASSERT_FALSE(hashTable.contain(0));
    ASSERT_FALSE(hashTable.contain(1));
}

TEST(dict_contains, set2) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(0, 103);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_FALSE(hashTable.contain(2));
    ASSERT_TRUE(hashTable.contain(0));
}

TEST(dict_contains, set3) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(0, 103);
    hashTable.add(1, 105);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_TRUE(hashTable.contain(0));
    ASSERT_TRUE(hashTable.contain(1));
    ASSERT_FALSE(hashTable.contain(2));
    ASSERT_FALSE(hashTable.contain(3));
}

TEST(dict_contains, set4) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(0, 103);
    hashTable.add(1, 105);
    ASSERT_FALSE(hashTable.contain(3));
    hashTable.add(2, 206);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_TRUE(hashTable.contain(1));
}

TEST(dict_contains, set5) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(0, 103);
    hashTable.add(1, 105);
    hashTable.add(2, 206);
    hashTable.add(4, 407);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_TRUE(hashTable.contain(1));
    ASSERT_TRUE(hashTable.contain(4));
    ASSERT_FALSE(hashTable.contain(7));
    ASSERT_FALSE(hashTable.contain(8));
}

TEST(dict_remove, empty) {
    // homework
    ArrayDictionary<int, int> hashTable;

    // ensures hasTable is empty
    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_FALSE(hashTable.remove(-1));
    ASSERT_FALSE(hashTable.remove(0));
    ASSERT_FALSE(hashTable.remove(1));
}

TEST(dict_remove, exist_noCollision) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(0, 103);
    hashTable.add(1, 105);
    hashTable.add(2, 206);
    hashTable.add(4, 407);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_TRUE(hashTable.remove(0));
    // ensures removal
    ASSERT_FALSE(hashTable.remove(0));
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict_remove, noExist_noCollision) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(4, 444);
    hashTable.add(7, 777);
    hashTable.add(8, 888);
    hashTable.add(9, 999);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_FALSE(hashTable.remove(0));
    ASSERT_FALSE(hashTable.remove(5));
}

TEST(dict_remove, exist_collision) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(4, 444);
    hashTable.add(14, 141);
    hashTable.add(24, 242);
    hashTable.add(16, 161);
    hashTable.add(6, 666);
    hashTable.add(8, 88);
    hashTable.add(18, 181);
    hashTable.add(8, 888);
#ifdef PRINT
    hashTable.print();
#endif

    // remove if first collision
    ASSERT_TRUE(hashTable.remove(8));
    // ensures removal
    ASSERT_FALSE(hashTable.remove(8));
#ifdef PRINT
    hashTable.print();
#endif

    //remove if last collision
    ASSERT_TRUE(hashTable.remove(6));
#ifdef PRINT
    hashTable.print();
#endif

    //remove if middle collision
    ASSERT_TRUE(hashTable.remove(14));
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict_remove, noExist_collision) {
    // homework
    ArrayDictionary<int, int> hashTable;
    hashTable.add(1, 111);
    hashTable.add(3, 333);
    hashTable.add(9, 999);
    hashTable.add(13, 131);
#ifdef PRINT
    hashTable.print();
#endif
    ASSERT_FALSE(hashTable.remove(6));
    ASSERT_FALSE(hashTable.remove(18));
}