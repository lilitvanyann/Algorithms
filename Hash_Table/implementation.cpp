#include <iostream>
#include <stack>
#include <vector>


class Node {
	public:
	int key;
	Node* next;
	Node* previous;
	Node(int _key) {
			key = _key;
			next = nullptr;
			previous = nullptr;
	}	

};

int hashfunction(int tablesize, int key) {

	return key % tablesize;

}

bool checkisPrime(int tablesize) {
		if (tablesize <= 1) 
				return false;
		int i = 2;
		while (i <= tablesize / 2 ) {
			if ( tablesize % i == 0) 
			return false;
			++i;	
		}
		
		//std::cout << "here\n";
		return true;

}

void hash_insert(std::vector<Node*> &hashtable, int key) {
			int index = hashfunction(hashtable.size(), key);		
			Node* currentnode = new Node(key);
			if (hashtable[index] != nullptr) {
					currentnode->next = hashtable[index];
					hashtable[index]->previous = currentnode;
			}

			hashtable[index] = currentnode;
			std::cout << "search is done\n";				 
}

Node* hash_search(std::vector<Node*> &hashtable, int targetkey) {
		int index = hashfunction(hashtable.size(), targetkey);
		
		Node* currentNode = hashtable[index];
		while(currentNode != nullptr) {
						if (targetkey == currentNode->key)
							return currentNode;
						currentNode = currentNode->next;	
		}

		std::cout << "the node with  " << targetkey << " key is not found\n";
		return nullptr;

}

void hash_delete(std::vector<Node*> &hashtable, int targetkey) {
    int index = hashfunction(hashtable.size(), targetkey);

    Node* currentNode = hashtable[index];

    while (currentNode != nullptr) {
        if (targetkey == currentNode->key) {

            if (currentNode->previous != nullptr) {
                currentNode->previous->next = currentNode->next;
            } 
            else {
                hashtable[index] = currentNode->next;
            }

            if (currentNode->next != nullptr) {
                currentNode->next->previous = currentNode->previous;
            }

            delete currentNode;
            return;
        }

        currentNode = currentNode->next;
    }
}


int main()
{
	int tablesize;
	while(1) {
	std::cout << "please input hash table size(choose prime number): ";
	std::cin >> tablesize;
				if (checkisPrime(tablesize))
						break;
	}

	std::vector<Node*> hashtable (tablesize, nullptr);

	hash_insert(hashtable, 6);
	hash_insert(hashtable, 20);
	hash_insert(hashtable, 15);

	Node* res1 = hash_search(hashtable, 6);
	if (res1 != nullptr)
		std::cout << "Found: " << res1->key << "\n";
	
	hash_insert(hashtable, 20);
	Node* res2 = hash_search(hashtable, 20);
	if (res1 != nullptr)
		std::cout << "Found: " << res1->key << "\n";

	hash_delete(hashtable, 20);
	hash_search(hashtable, 20);

	//print hashtable
	for (int i = 0; i < hashtable.size(); ++i) {
		std::cout << "Bucket " << i << ": ";
		Node* current = hashtable[i];  // T[i] head pointer
	    
    	    while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
    }
    std::cout << "\n";
}

	return 0;

}
