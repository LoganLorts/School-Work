// Programmer:	Logan Lorts
// Date:	4/17/2023
// Section:	102

#include <iostream>
#include <string>
#include "randomengine.h"
#include "queue.h"

class customer
{
    public:
    string name;
    int order = 0;
    int popplers_eaten = 0;

    customer()
    {
        name = "";
        order = 0;
    }
    customer(string customer, int spot, int popplers)
    {
        name = customer;
        order = spot;
        popplers_eaten = popplers;
    }
};

int main()
{
    int num_customers = 0;
    int total_popplers = 0;
    int most_eaten = 0;
    int least_eaten = 0;
    string name_most_eaten;
    string name_least_eaten;
    Queue<customer> customer_queue;
    randomEngine re;

    cin >> num_customers;
    for(int i=0; i < num_customers; i++)
    {
        string n;
        int o;
        cin >> n;
        cin >> o;
        customer_queue.enqueue(customer(n,o,0));
    }
    least_eaten = (((customer_queue.front().order -1) /5)+1) * 5;
    name_least_eaten = customer_queue.front().name;

    while (!customer_queue.isEmpty())
    {
        int more_popplers = 0;
        customer *cust = new customer;

        cust->name = customer_queue.front().name;
        cust->order = (((customer_queue.front().order -1) /5)+1) * 5;
        cust->popplers_eaten = customer_queue.front().popplers_eaten + cust->order;
        total_popplers += cust->order;


        for(int i = 0; i < customer_queue.front().order; i++)
        {
            if(re.rollD(6) == 6)
            {
                more_popplers += 1;
            }
        }

        if(more_popplers)
        {
            cout << cust->name << " eats " << cust->order << " popplers. ";
            if(more_popplers == 1)
            {
                cout << cust-> name << " wants one more poppler!" << endl;
            }
            else
            {
                cout << cust->name << " wants " << more_popplers << " more popplers!" << endl;
            }
            cust->order = more_popplers;
            customer_queue.enqueue(*cust);
        }
        else
        {
            cout << cust->name << " eats " << cust->order << " popplers. ";
            cout << cust->name << " is satisfied after eating " << cust->popplers_eaten << " popplers." << endl;
        }
        
        if(cust->popplers_eaten > most_eaten)
        {
            most_eaten = cust -> popplers_eaten;
            name_most_eaten = cust ->name;
        }
        else if(cust->popplers_eaten < least_eaten)
        {
            least_eaten = cust->popplers_eaten;
            name_least_eaten = cust->name;
        }
        customer_queue.dequeue();
        delete cust;
    }

    cout << "A total of " << total_popplers << " popplers were eaten." << endl;
    cout << name_most_eaten << " ate the most popplers: " << most_eaten << endl;
    cout << name_least_eaten <<" ate the fewer popplers: " << least_eaten << endl;
    return 0;
}
