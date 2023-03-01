#include <string>
#include <iostream>
#include <vector>
#include <Task.hxx>
using namespace std;

class TaskList {
    protected:
        vector<Task> taskQueue;
  
    public:
        TaskList() {
            taskQueue = vector<Task>();
        }

        int numTasks() {
            return taskQueue.size();
        }

        bool isEmpty() {
            return taskQueue.size() == 0;
        }

        void addTask(Task task) {
            //Push new task onto back of vector
            taskQueue.push_back(Task());

            //Min Heap Priority Queue Enqueue algorithm
            int insertPos = taskQueue.size() - 1;
            int parent = (insertPos - 1)/2;

            while(parent >= 0 && taskQueue.at(parent).overallPriority() > task.overallPriority()) {
                taskQueue.at(insertPos) = taskQueue.at(parent);
                insertPos = parent;
                parent = (insertPos - 1)/2;
            }
            taskQueue.at(insertPos) = task;

        }

        Task nextTask(bool remove = true) {
            Task top = taskQueue.at(0);
            //Optionally specify not to remove next task, defaults to removing next task
            if(remove) {
                //Min Heap Priority Queue Dequeue algorithm
                int currPos = 0;
                int LKey = 2 * currPos + 1;
                int RKey = 2 * currPos + 2;

                while(LKey < taskQueue.size()) {
                    //Find which child is higher priority
                    int minKey;
                    if(RKey == taskQueue.size()) {
                        //Left child is last element in heap - highest priority child by default
                        minKey = LKey;
                    } else if(taskQueue.at(LKey).overallPriority() < taskQueue.at(RKey).overallPriority()) {
                        minKey = LKey;
                    } else {
                        minKey = RKey;
                    }

                    //Swap with highest priority task
                    Task moveDown = taskQueue.at(currPos);
                    taskQueue.at(currPos) = taskQueue.at(minKey);
                    taskQueue.at(minKey) = moveDown;

                    //Recalculate currPos, LKey, and RKey
                    currPos = minKey;
                    LKey = 2 * currPos + 1;
                    RKey = 2 * currPos + 2;
                }
                taskQueue.erase(taskQueue.begin() + currPos);  
            }
            return top;
        }
};