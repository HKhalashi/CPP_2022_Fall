#include <iostream>

int main(int argc, char* argv[])
{
    int capacity = 10;
    int count = 0;
    int* a = (int*)malloc(sizeof(int) * capacity);
    int in = 0;

    do
    {
        std::cout << "0 - Exit\n";
        std::cout << "1 - Add\n";
        std::cout << "2 - Print\n";
        std::cout << "3 - Delete\n";
        std::cout << "4 - Swap\n";
        std::cin >> in;
        switch (in)
        {
            case 1:
            {
                std::cout << "input element: ";
                if (count == capacity)
                {
                    int* t = (int*)malloc(sizeof(int) * (capacity + 5));
                    for (int i = 0; i < capacity + 5; ++i)
                    {
                        *(t + i)= (i < capacity ? *(a + i) : 0);
                    }
                    free(a);
                    a = t;
                    capacity += 5;
                }
                std::cin >> *(a + count);
                ++count;
                break;
            }
            case 2:
            {
                std::cout << "a = ";
                for (int i = 0; i < count; ++i)
                {
                    std::cout << *(a + i) << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 3:
            {
                unsigned index = 0;
                std::cout << "input index: ";
                std::cin >> index;
                if(index >= 0 && index < count){
                    int* t = (int*)malloc(sizeof(a) - sizeof(*(a + index)));
                    int j = 0;
                    for (int i=0; i < count; i++)
                    {
                        if(i != index){
                            *(t+j) = *(a+i);
                            j++;
                        }
                    }
                    free(a);
                    a = t;
                    --count;
                }
                else{
                    std::cout << "invalid index , try again" << std::endl;
                }
                break;
            }
            case 4:
            {
                unsigned index_1 = 0;
                unsigned index_2 = 0;
                std::cout << "enter index_1 :";
                std::cin >> index_1;
                std::cout << "\nenter index_2:";
                std::cin >> index_2;
                if(index_1 >= 0 && index_1 < count && index_2 >= 0 && index_2 < count){
                    int el_1 = *(a + index_1);
                    int el_2 = *(a + index_2);
                    *(a + index_1) = el_2;
                    *(a + index_2) = el_1;
                }
                else{
                    std::cout << "invalid index , try again" << std::endl;
                }
                break;
            }
        }
        system("pause");
        system("cls");

    } while (in != 0);

    free(a);
    return EXIT_SUCCESS;
}
