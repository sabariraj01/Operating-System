//Simulation of Round-Robin Scheduling algorithm used in Operating systems//
//Fixed time slice of 2 is used.Process queue is implemented a sLinked list//
//The program is tuned for 10 processes and Buurst times need to be entered//


#include <stdio.h>
#include <iostream>
#include <malloc.h>


struct node
{
	int arrival;
	int burst;
	int burst1;
	int turnaround;
	int waiting;
	int finish;
	int res;
	int name;

	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;


int empty()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

void append (struct node *temp)
{			
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp->next=NULL;
	}
	else
	{
		tail -> next = temp;
		tail = temp;
		tail -> next = NULL;
	}
}

struct node* serve ()
{
	struct node *temp;
	if (!empty())
	{
		temp = head;
		head = head -> next;

		return temp;			
	}
	else
	{
		//std::cout<<"Ready q is empty"<<"\n";
		temp = new(node);
		temp -> name = 0;
		return temp;
	}
}	

int main()
{
	int max;

	struct node *p[10];
	struct node *exe;

	int quantum;
	int period = 0;
	int count = 0;
	int i;
	int choice;

	double totalWaiting = 0;
	double avgWaiting;
	
//	std::cout<<"Enter number of process taken :";
	std::cin>>max;
	
//	std::cout<<"Enter Time Quantum value: ";
	std::cin>>quantum;

 for (i = 0; i < max; i++)
		{	p[i] =new(node);
			p[i] -> turnaround = 0;
			p[i] -> waiting = 0;
			p[i] -> finish = 0;
			p[i] -> name = i + 1;
			p[i] -> res=-1;
			p[i] -> next = NULL;
		}

			for (i = 0; i < max; i++)
			{
				std::cin>>p[i] -> arrival;
			//	std::cout<<i<<" arival time is "p[i]->arrival << "\n";
			}

		for (i = 0; i < max; i++)
		{
			std::cin>>p[i] -> burst; 
			p[i] -> burst1 = p[i] -> burst;
		}


		int t=0;
	while (count < max)
		{
				while(t < max && p[t]->arrival <= period ) 
				{					
						append (p[t]);
						t=t+1;
				}
			exe = new(node);
			exe = serve();
        //    getchar();
			if (exe -> name != 0)
			{
				if( exe -> res ==-1)
				     exe -> res=period - exe->arrival;
				if (exe -> burst1 > quantum)
				{
//				printf ("%d\t\t", period); 
					exe -> burst1 = exe -> burst1 - quantum;
					period = period + quantum;

//					printf ("%d\t\t%d\t\t%d\t\t%d\tQ\n", period, exe -> name, exe -> arrival, exe -> burst1);
					
					if (choice ==2 || choice ==3)
					{
						while(t < max && p[t]->arrival <= period ) 
						{					
							append (p[t]);
							t=t+1;
						}
					}

						append (exe); 
							
//					getch();
				} 
				else
				{
					//if (exe -> burst1 != 0)
					{
//						std::cout<< period<<"   ";
						period = period + exe -> burst1;
						exe -> burst1 = 0;
						exe -> finish = period;
						exe -> turnaround = exe -> finish - exe -> arrival;
						exe -> waiting = exe -> turnaround - exe -> burst;

						count ++;

						for (i = 0; i < max; i++)
						{
							if (p[i] -> name == exe -> name)
							{
								p[i] = exe;
							}
						}


//						printf ("\t\t%d\t\t%d\t\t%d\t\t%d\tFinish\n", period, exe -> name, exe -> arrival, exe -> burst1);						
						
//						getch();
					}
				}
			} 
			else
			{
									

				period = period + 1;
									
			}		
		} 

//		std::cout<<" \n\n\n";

//		printf("Process\t\tFinish time\t\tTurnAround time\t\tWaiting time\t\t Response Time\n");

		int totalturnaround=0;
		int totalres=0;
		for (i = 0; i < max; i++)
		{totalWaiting = totalWaiting + p[i] -> waiting;
		  totalturnaround= totalturnaround + p[i]->turnaround;
		  totalres=totalres + p[i] -> res;
		}
		avgWaiting = totalWaiting / max;
		double avgTT=totalturnaround*1.0/max;
		double avgres=totalres*1.0/max;
		//std::cout<<"\n\n";
		std::cout<<avgWaiting<<"\n";
		std::cout<<avgTT<<"\n";
		std::cout<<avgres<<"\n";
		
} 
