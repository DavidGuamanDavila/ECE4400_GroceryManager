#pragma once
using namespace std;

// CQ Class Begins
template <typename T>
class CQ
{
	// Initialize front and rear
	int rear, front;
	// Initialize variable that will store the size of the array
	int SIZE;
	//Initialize the array
	T* content;
public:
	CQ(int valueofsize)
	{
		//Set front and rear to -1 which denotes the CQ is empty
		front = rear = -1;
		//Define the variable that stores the size of the array
		SIZE = valueofsize;
		//Define the array
		content = new T[SIZE];
	}

	//Function to enqueue a value into CQ
	void enQueue(T value)
	{
		//Address scenario where the CQ is full
		if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
		{
			//Call function to Dequeue
			deQueue();
			//Call function to Enqueue the value
			enQueue(value);
		}
		//Address scenario where the CQ is empy. Hence, inserting the first element
		else if (front == -1)
		{
			front = rear = 0;
			content[rear] = value;
		}
		//Address scenerio where a deletion previously occured and there exists space for insertion
		else if (rear == SIZE - 1 && front != 0)
		{
			rear = 0;
			content[rear] = value;
		}
		//Address scenerio to just insert
		else
		{
			rear++;
			content[rear] = value;
		}
	}
	// Function delete a value from the CQ
	T deQueue()
	{
		//Address sceneario where the queue is empty
		if (front == -1)
		{
			cout << "No customer information to dequeue." << endl;
			return "Nothing";
		}
		//Create temporary data
		T data = content[front];
		content[front] = -1;
		if (front == rear)
		{
			front = rear = -1;
		}
		else if (front == SIZE - 1)
			front = 0;
		else
			front++;
		return data;
	}

	//Function that traverses the CQ and displays the contents of the CQ
	void displayQueue()
	{
		if (front == -1)
		{
			cout << "No customer information to display.";
			return;
		}
		cout << "These are the most recent customers: ";
		if (rear >= front)
		{
			for (int j = front; j <= rear; j++)
				cout << content[j] << ", ";
		}
		else
		{
			for (int j = front; j < SIZE; j++)
				cout << content[j] << ", ";
			for (int j = 0;j <= rear; j++)
				cout << content[j] << ", ";
		}
		cout << endl;
	}
	//Destructor
	~CQ() {
		delete[] content;
	}
};
// CQ Class Ends



