#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

//////////////////////////////////#include "Heap.ipp"

#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize = START_SIZE;
  numItems=0;
  backingArray = new std::pair<Pri, T>[arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  std::pair<Pri, T>* newArray = new std::pair<Pri,T>[2*arrSize];
  for(int k = 0; k < numItems; k++){
	  newArray[k] = backingArray[k];
  }
  arrSize = arrSize * 2;
  delete[] backingArray;
  backingArray = newArray;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  if(numItems + 1 > arrSize) 
	  grow();
  backingArray[numItems] = toAdd;
  bubbleUp(numItems);
  numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	int pindex = (index - 1) / 2;
	if(backingArray[pindex].first > backingArray[index].first && index > 0){
		backingArray[pindex].swap(backingArray[index]);
		index = pindex;
		bubbleUp(pindex);
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	int i = index;

	do{
		int j = -1;
		int rdex = (index * 2) + 2;
		if((rdex < numItems) && (backingArray[rdex].first < backingArray[i].first)){
			int ldex = (index * 2) + 1;
			if(backingArray[ldex].first < backingArray[rdex].first)
				j = ldex;
			else
				j = rdex;
		}else {
			int ldex = (index * 2) + 1;
			if(ldex < numItems && (backingArray[ldex].first < backingArray[i].first))
				j = ldex;
		}

		if(j >= 0)
			backingArray[i].swap(backingArray[j]);
		i=j;
	}while(i>=0);
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri, T> ret = backingArray[0];
  numItems--;
  backingArray[0] = backingArray[numItems];
  trickleDown(0);
  return ret;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}

