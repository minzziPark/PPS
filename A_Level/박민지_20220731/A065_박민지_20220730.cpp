/*
Source: https://www.acmicpc.net/problem/11650

좌표 정렬하기

문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

//////////////////////////Linked List로 풀었는데 시간초과뜸//////////////////////
/*
#include <iostream>
using namespace std;

struct ListNode{
	int x;
	int y;
	ListNode* next;
	//ListNode* pred;
};

int main(){
	int N, x, y;
	cin >> N;
	ListNode* listNode = nullptr;

	for(int i=0; i<N; i++){
		cin >> x;
		cin >> y;
		if(listNode == nullptr){
			listNode = new ListNode;
			listNode->x = x;
			listNode->y = y;
			listNode->next = nullptr;
			//listNode->pred = nullptr;
			//cout << "되나?" << endl;
			continue;
		}

		ListNode* node = new ListNode;
		node->x = x;
		node->y = y;

		ListNode* head = listNode;
		ListNode* pred = nullptr;
		while(head != nullptr){
			//앞에 껴는 경우
			if((head->x == node->x && head->y >= node->y) || (head->x > node->x)){
				
				if(pred == nullptr){
					node->next = head;
					listNode = node;
					//cout << head->x << ", " << node->x << endl;
				}else{
					pred->next = node;
					node->next = head;
				}
				break;
			}
			pred = head;
			head = head->next;
		}

	}
	ListNode* head = listNode;
	while(head != nullptr){
		cout << head->x << " " << head->y << endl;
		head = head->next;
	}

	return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<pair<int, int>> vec;
	int N, x, y;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> x;
		cin >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end());

	for(int i=0; i<N; i++){
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	return 0;
}