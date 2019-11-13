// Specification of ADT Buckets
//    data object: buckets with one pebble in each bucket
//    operations:

#ifndef BUCKETS_H
#define BUCKETS_H

struct BucketStuff;

enum Pebble {RED, WHITE, BLUE};

class Buckets
{
public:

// Adam and Drew
// creates the buckets in front of the robot
Buckets();

//Bo and Matt
// trashes the buckets 
~Buckets();

//Andrew and Scott
void look (Pebble& color, int bucketNumber);

//Evan and Ryan
void swap(int bucket1, int bucket2);

//Megan, Alli, Esther
// puts a random pebble in each bucket
void fillBuckets();

private:

BucketStuff* buckets;

};
#endif




