#include "MinDistancePolyLines.h"

using namespace std;

int main(int argc, char**argv)
{

	//Init polylines 1 and 2. There is a possibility to add more points here, as desired
	initPoints(polyline1, polyline2);

	//determine if the polylines are closer than a given threshold
	bool result = arePolylinesCloserThanThreshold(polyline1, polyline2);

	if(result)
		std::cout << "True, because the minimum distance is " << minDist << std::endl;
	else
		std::cout << "False, because the minimum distance is " << minDist << std::endl;

	return 1;	
}

/**************************************************************************
Function Name    : initPoints
Parameters		 : two polylines polyline1 and polyline 2
Returns			 : void
Function		 : Initialise the polylines with the desired points
Author			 : Anupama Rajkumar
****************************************************************************/

void initPoints(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2)
{
	//adding points to polyline 1
	polyline1.push_back(sPoint2D(2.0, 3.0));
	polyline1.push_back(sPoint2D(3.0, 4.0));
	polyline1.push_back(sPoint2D(2.0, 6.0));
	std::cout << "coordinates of polyline - 1 \n";
	for (auto p1 : polyline1) {
		std::cout << p1.x << " " << p1.y << endl;;
	}

	//adding points to polyline 2
	polyline2.push_back(sPoint2D(5.0, 6.0));
	polyline2.push_back(sPoint2D(5.0, 4.0));
	polyline2.push_back(sPoint2D(7.0, 4.0));
	polyline2.push_back(sPoint2D(7.0, 2.0));
	//add additional points in this manner
	/*polyline2.push_back(sPoint2D(4.0, 9.0));
	polyline2.push_back(sPoint2D(9.0, 1.0));
	polyline2.push_back(sPoint2D(8.0, 7.0));
	polyline2.push_back(sPoint2D(6.0, 2.0));*/
	std::cout << "coordinates of polyline - 2 \n";
	for (auto p2 : polyline2) {
		std::cout << p2.x << " " << p2.y << endl;
	}
}

/*****************************************************************************************************
Function Name    : arePolylinesCloserThanThreshold
Parameters		 : two polylines - polyline1 and polyline 2
Returns			 : true or false based on whether the distance between polylines is less than threshold
Function		 : User option to find nearest neighbor using different user inputs
Author			 : Anupama Rajkumar
*****************************************************************************************************/

bool arePolylinesCloserThanThreshold(std::vector<sPoint2D>& polyline1, std::vector<sPoint2D>& polyline2) {
	int choice = 1;
	bool closerThanThreshold = true;
	cout << "Please enter choice between naive or KD-tree based nearest neighbor calculation (1/2)" << std::endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		/*Nearest neighbors using naive method*/
		FindNearestNeighbor_Naive(polyline1, polyline2);
		break;
	case 2:
		/*Nearest neighbors using KD-Tree*/
		FindNearestNeighbor_KDTree(polyline1, polyline2);
		break;
	default:
		std::cerr << "Please enter a valid choice" << std::endl;
		break;
	}
	if (minDist < distThresh) {
		closerThanThreshold = true;
	}
	else
	{
		closerThanThreshold = false;
	}
	return closerThanThreshold;
}

/*****************************************************************************************************
Function Name    : FindNearestNeighbor_Naive
Parameters		 : two polylines - polyline1 and polyline 2
Returns			 : void
Function		 : Naive method to find nearest neighbor where each point in polyline1 calculates distance
					from each point in polyline2 and finds the minimum distance in this fashion
Author			 : Anupama Rajkumar
*****************************************************************************************************/
void FindNearestNeighbor_Naive(std::vector<sPoint2D>& polyline1,
							   std::vector<sPoint2D>& polyline2) {
	std::vector<float> distance;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	for (auto p1 : polyline1) {
		for (auto p2 : polyline2) {
			float dist = EucDist(p1.x, p1.y, p2.x, p2.y);
			distance.push_back(dist);
		}
	}
	std::sort(distance.begin(), distance.end());	
	minDist = distance[0];
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_elapsed = end - start;
	std::cout << "Time needed for naive computation: " << time_elapsed.count() << std::endl;
}

/*****************************************************************************************************
Function Name    : FindNearestNeighbor_KDTree
Parameters		 : two polylines - polyline1 and polyline 2
Returns			 : void
Function		 : Creation of KD-Tree and traversing through the tree to determine the smallest distance
				   between the points of line
Author			 : Anupama Rajkumar
*****************************************************************************************************/

void FindNearestNeighbor_KDTree(std::vector<sPoint2D>& polyline1,
								std::vector<sPoint2D>& polyline2) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	//1. Step 1 - Create a KD Tree
	root = CreateKDTree(polyline2);
	//2. Step 2 - find nearest neighbor in the KDTree
	//for each point in the first line, traverse through the created tree to determine the smallest distance
	for (int i = 0; i < polyline1.size(); i++) {
		FindNearestNeighbor(root, polyline1[i], 0);
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_elapsed = end - start;
	std::cout << "Time needed for KD-Tree computation: " << time_elapsed.count() << std::endl;

}
/*****************************************************************************************************
Function Name    : CreateKDTree
Parameters		 : points of polyline2
Returns			 : pointer to root node
Function		 : Creation of KD-Tree. Inserting each point in the polyline2 to form the tree
Author			 : Anupama Rajkumar
*****************************************************************************************************/
KDNode* CreateKDTree(std::vector<sPoint2D>& polyline2) {
	for (size_t i = 0; i < polyline2.size(); i++) {
		root = InsertNode(root, polyline2[i], 0);
	}
	return root;
}

/*****************************************************************************************************
Function Name    : InsertNode
Parameters		 : pointer to root node, point to be inserted, depth of tree at which the point should
					be inserted
Returns			 : pointer to root node
Function		 : Recursive function to add each point to the tree based on the plane in which the point
					belongs
Author			 : Anupama Rajkumar
*****************************************************************************************************/

KDNode* InsertNode(KDNode *root, sPoint2D point, unsigned int depth) {
	
	if (root == NULL) {
		KDNode *newNode = (KDNode *)malloc(sizeof(KDNode));
		newNode->point.x = point.x;
		newNode->point.y = point.y;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	//check the dimension -x or y to determine the cutting plane of the tree
	unsigned int currDim = depth % k;
	//if the point cuts the x plane, compare the x dim values of the point with that of root
	if (currDim == 0) {
		if (point.x < (root->point.x)) {
			//insert to left side of tree for smaller x dim
			root->left = InsertNode(root->left, point, depth+1);
		}	
		else {
			//insert to right side of tree for greater x dim
			root->right = InsertNode(root->right, point, depth+1);
		}
			
	}
	//if the point cuts the y plane, compare the y dim values of the point with that of root
	else {
		//insert to left side of tree for smaller y dim
		if (point.y < (root->point.y)) {
			root->left = InsertNode(root->left, point, depth+1);
		}
		//insert to right side of tree for greater y dim
		else {
			root->right = InsertNode(root->right, point, depth+1);
		}			
	}
	return root;
}

/*****************************************************************************************************
Function Name    : EucDist
Parameters		 : x and y coordinates of two points p1 and p2
Returns			 : euclidean distance value
Function		 : calculates euclidean distance between point 1 and point 2
Author			 : Anupama Rajkumar
*****************************************************************************************************/

inline float EucDist(float p1X, float p1Y, float p2X, float p2Y) {
	float dist = std::pow((p1X - p2X), 2) + std::pow((p1Y - p2Y), 2);
	dist = std::sqrt(dist);
	return dist;
}

/**********************************************************************************************************
Function Name    : FindNearestNeighbor
Parameters		 : pointer to root node, query point, tree depth
Returns			 : bool depending on whether smallest distance found or not
Function		 : Traverse through the KD-Tree to calculate the smallest distance between points of polylines
Author			 : Anupama Rajkumar
**********************************************************************************************************/

bool FindNearestNeighbor(KDNode *root, sPoint2D point, unsigned int depth) {
	float localDist = std::numeric_limits<float>::max();
	//exit after reached leaf or if root is null
	if (root == NULL) {
		return false;
	}
	//calculate the distance between current root node the query point
	localDist = EucDist(point.x, point.y, root->point.x, root->point.y);
	//update the minimum distance if the value of distance is lower
	if (localDist < minDist) {
		minDist = localDist;
	}
	// determine the plane which the point cuts
	unsigned int currDim = depth % k;
	//if the point cuts x dimension
	if (currDim == 0) {
		//go towards right children if the x dim is lower to find the nearest neighbor
		if (point.x < root->point.x) {
			//the good side of the tree
			FindNearestNeighbor(root->left, point, depth + 1);

		}
		//the bad side of the tree
		/*if the distance on the bad side of the tree is more than the min dist at good 
		side, dont traverse in that direction and return*/
		if (localDist > minDist) {
			return false;
		}
		FindNearestNeighbor(root->right, point, depth + 1);
	}
	else {
		//if the point cuts y dimension
		//go towards right children if the y dim is lower to find the nearest neighbor
		if (point.y < root->point.y) {
			//the good side of the tree
			FindNearestNeighbor(root->left, point, depth + 1);
		}
		//the bad side of the tree
		/*if the distance on the bad side of the tree is more than the min dist at good
		side, dont traverse in that direction and return*/
		if (localDist > minDist) {
			return false;
		}
		FindNearestNeighbor(root->right, point, depth+1);
	}
	return true;
}


