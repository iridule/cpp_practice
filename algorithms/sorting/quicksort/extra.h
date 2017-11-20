// test case
struct testCase {

    // arbitrary size array
    unsigned int length;
    int * array;

    // left and right dimensions
    int left;
    int right;

    //
    void fillArray() {
        length = std::floor(5 + std::rand() % 8);
        array = new int[length];
        for (int i = 0; i < length; i++)
            array[i] = (int) std::rand() % 500;
    }

    void reset() {
        delete array;
    }

    //
    testCase() {
        fillArray();
    }

};