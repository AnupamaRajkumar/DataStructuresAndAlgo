#pragma once
#ifndef __MINDIST__
#define __MINDIST__

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>

/*******Declare variables*********/

struct sPoint2D {
	sPoint2D(float xValue, float yValue) {
		x = xValue;
		y = yValue;
	}
	float x;
	float y;
};

/*define the polylines*/
std::vector<sPoint2D> polyline1;
std::vector<sPoint2D> polyline2;
const float distThresh = 1.5;
float minDist = std::numeric_limits<float>::max();

/*variables for kd tree*/
typedef struct Node {
	sPoint2D point;
	Node *left, *right;
}KDNode;

KDNode *root = NULL;

const int k = 2; //x and y dimensions

/********Function declarations*********/

void initPoints(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2);
inline float EucDist(float p1X, float p1Y, float p2X, float p2Y);

bool arePolylinesCloserThanThreshold(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2);
void FindNearestNeighbor_Naive(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2);
void FindNearestNeighbor_KDTree(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2);

/*funtions for kd tree*/
KDNode* CreateKDTree(std::vector<sPoint2D>& polyline2);
KDNode* InsertNode(KDNode *root, sPoint2D point, unsigned int depth);
bool FindNearestNeighbor(KDNode *root, sPoint2D point, unsigned int depth);


#endif // !__MINDIST__

