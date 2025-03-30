#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    ofstream myfile;

    myfile.open("Ising Model using Monte Carlo");
}

void configuration()

{

    int system[100];
    const int J = 1;

    srand(time(0));

    int num_population = 100;

    for (int i=0; i<=num_population; i++)
    {
        int rand_state = rand()%1;
        if (rand_state == 0) rand_state = -1;
        system[i] = rand_state;
    }

    int randomisation_iters = exp(2, 100);
    for (int k=0; k < randomisation_iters ; k++)
    {
        int rand_choice_index = rand()%(num_population -1);
        system[rand_choice_index] = -1*system[rand_choice_index];

        bool change_one = 0;

        if (rand_choice_index == 0 || rand_choice_index == num_population-1)
        {
            change_one = 1;
        }

        int change_in_energy;

        if (!change_one)
        {
            int energy_1 = -J * (system[rand_choice_index] * system[rand_choice_index + 1]*);
            int energy_2 = -J * (system[rand_choice_index] * system[rand_choice_index - 1]);

            change_in_energy = energy_1 + energy_2;
        }
        else if(rand_choice_index == 0)
        {
            change_in_energy = -J * system[rand_choice_index] * system[rand_choice_index + 1];
        }
        else
        {
            change_in_energy = -J * system[rand_choice_index] * system[rand_choice_index-1];
        }

        int beta;

        int P = exp(-beta * change_in_energy);
        if (P >1) P = 1;

        int rand_num = (rand()%10000) / 1e5;
        if (rand_num <P)
        {
            system[rand_choice_index] = -1 * system[rand_choice_index];
            if (!change_one)
            {
                int energy_1 = -J * (system[rand_choice_index] * system[rand_choice_index + 1]*);
                int energy_2 = -J * (system[rand_choice_index] * system[rand_choice_index - 1]);

                change_in_energy = energy_1 + energy_2;
            }
            else if(rand_choice_index == 0)
            {
                change_in_energy = -J * system[rand_choice_index] * system[rand_choice_index + 1];
            }
            else
            {
                change_in_energy = -J * system[rand_choice_index] * system[rand_choice_index-1];
            }
        }
    
        int magnetisation = 0;
        int total_energy = 0;

        for (int i = 0; i < num_population-1; i++)
        {
            total_energy += -J * (system[i]*system[i+1]);
            magnetisation += system[rand_choice_index];
        }
        
        magnetisation += system[num_population-1];
    }
}

int num_configs = 


int main()
{
    return 1;
}

