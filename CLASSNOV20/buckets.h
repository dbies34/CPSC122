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
// pre: buckets exists
// post: empty Buckets are made
// usage: Buckets b;
Buckets(int numberBuckets);

//Bo and Matt
// destroys the buckets object
// pre: buckets object exists
// post: buckets object does not exist
// usage: automatically done at the end of scope
~Buckets();

//Andrew and Scott
//looks inside the bucket and determines what color 
//  the pebble is and what number the bucket that was looked into is
//pre: the struct of buckets has been created and there is a red, white, or blue pebble in each of the buckets
//post: the color of the pebble is returned and where that pebble is located 
void look (Pebble& color, int bucketNumber);

//Evan and Ryan
//pre: leftBucket and rightBucket are positions of buckets
//post: the contents at position leftBucket has been switched with the contents at position rightBucket
//		robot's left arm finds position of leftBucket starting from the left
//		robot's right arm finds position of rightBucket starting from the right
//usage: swap(leftBucket, rightBucket);
void swap(int leftBucket, int rightBucket);

//Megan, Alli, Esther
//Puts a random color pebble in each bucket
//pre: buckets have been created and are in front of robot
//post: all buckets contain one pebble
//usage: robot.fillBuckets();
void fillBuckets();

private:

BucketStuff* buckets;

};
#endif




