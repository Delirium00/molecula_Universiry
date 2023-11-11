#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

int t;


int main()
{
    //двумерный массив с элементами - 0
    int const m = 10;
    int const n = 10;
    int array[n][m]{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // int array[n][m];

    // // автоматическое зануление каждого элемента
    // for (int i = 0; i < n; i++)
    // {
    //         for (int j = 0; j < m; j++)
    //         {
    //             array[i][j] = 0;
    //         }
    // }


    //вывод всех элементов через пробел
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;



    // обозначение нижней и верхней границ генерации
    // иницифлизация вихря мерсенна
    int lower_bound = 0;
    int upper_bound = 9;
    unsigned seed = static_cast<unsigned>(time(nullptr));
    mt19937 rng(seed);
    int move;

    for (int i = 0; i < 1000000; i++)
    {
    // i - количество монте-карло шагов
        for (int j = 0; j <= (n * m); j++)
        {
            // n*m - один шаг
            // генерация случайных координат
            uniform_int_distribution<int> distribution(lower_bound, upper_bound);
            int random_n = distribution(rng);
            int random_m = distribution(rng);

            bool T = true;
            if (T) 
            {
                uniform_int_distribution<int> distribution(0, 100);
                t = distribution(rng);
            }


            if (t > 2)
            {
                {
                    uniform_int_distribution<int> distribution(0, 4);
                    move = distribution(rng);
                    // move определяет соседнюю клетку, куда молекула может перейти в ходе диффузии 


                    if (array[random_n][random_m] == 1)
                    {
                        // диффузия
                        if (array[(random_n + n - 1) % n][random_m] == 0 & move == 0)
                        {
                            array[random_n][random_m] = 0;
                            array[(random_n + n - 1) % n][random_m] = 1;
                            
                        }
                        else if (array[random_n][(random_m + 1 + m) % m] == 0 & move == 1)
                        {
                            array[random_n][random_m] = 0;
                            array[random_n][(random_m + 1 + m) % m] = 1;
                            
                        }
                        else if (array[(random_n + n + 1) % n][random_m] == 0 & move == 2)
                        {
                            array[random_n][random_m] = 0;
                            array[(random_n + n + 1) % n][random_m] = 1;
                            
                        }
                        else if (array[random_n][(random_m + m -1) % m] == 0 & move == 3)
                        {
                            array[random_n][random_m] = 0;
                            array[random_n][(random_m + m -1) % m] = 1;
                            
                        }
                    }
                    
                }
            }

            // адсорбция-дисорбция
            else
            {
                if (array[random_n][random_m] != 1)
                {
                    array[random_n][random_m] = 1;
                }

                // ставится 0, если рандомно выбрал 1 и наоборот

                else
                {
                    array[random_n][random_m] = 0;
                }
            }



            // //вывод массива
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << array[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }


        
        
    }

    //вывод массива
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    // степень покрытия
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == 1)
            {
                s++;
            }
        }
    }
    cout << "S = " << s / 100;


    return 0;
}
