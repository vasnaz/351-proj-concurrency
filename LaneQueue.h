#pragma once
#include <cstdio>
#include <cstdlib>
#include "car.h"
using namespace std;

#define MAX_CARS 400

class LaneQueue {
public:
	LaneQueue();
	~LaneQueue();
	bool isEmpty() const;
	int size() const;
	const Car front() const;
	void enqueue(const Car car);
	void dequeue();
private:
	Car cars[MAX_CARS];
	int front, rear, size;
}

LaneQueue::LaneQueue() {
	this->front = 0;
	this->rear = 0;
	this->size = 0;
}

LaneQueue::~LaneQueue() {

}

bool Car::isEmpty() {
	return (n==0);
}

int Car::size() {
	return size;
}

const Car LaneQueue::front() const {
	if (empty()) throw length_error("front of empty queue");
	return cars[front];
}

void LaneQueue::enqueue(const Car car) {
	if (size() == MAX_CARS) throw length_error("enqueue to full queue");
	cars[r]=car;
	r = (r+1) % MAX_CARS;
	n++;
}

void LaneQueue::dequeue() {
	if (empty()) throw length_error("enqueue from empty queue");
	f = (f+1) % MAX_CARS;
	size--;
}
