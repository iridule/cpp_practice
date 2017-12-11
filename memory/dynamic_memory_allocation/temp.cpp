    int *i;
    i = new int(5);
    std::cout << *i << std::endl;
    int **pi;
    pi = new int*;
    *pi = new int(15);
    std::cout << **pi << std::endl;
