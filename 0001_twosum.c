/**
 * 给定一个整数数组和一个值target，求两个下标i、j，使得a[i] + a[j] = target，返回下标
 *
 */
 
/**
 * 使用哈希表，不断记录每个元素对应的下标，，然后查找target-a[i]，查找到了就有，查找不到就没有
 * 使用C语言的一个好处是你必须手动实现哈希表操作，没有现成的接口可以使用
 */

typedef struct HashNode {
	int key;
	int val;
} HashNode;

typedef struct HashMap {
	int size;
	HashNode **storage;
} HashMap;

/**
 * 创建哈希表
 */
HashMap * hash_create(int size) 
{
	HashMap *hashmap = malloc(sizeof(HashMap));
	hashmap->size = size;
	hashmap->storage = calloc(size, sizeof(HashNode *));
	return hashmap;
}

/**
 * 删除哈希表
 */
void hash_destory(HashMap *hashmap)
{
	int i;
	HashNode *node;
	for (i = 0; i < hashmap->size; i++) {
		node = hashmap->storage[i];
		if (node) {
			free(node);
		}
	}
	free(hashmap->storage);
	free(hashmap);
}

void hash_set(HashMap *hashmap, int Key, int val)
{
	int hash;
	HashNode *node;
	
	/* 为什么不用考虑哈希冲突的情况 */
	hash = abs(key) % hashmap->size;
	while (node = hashmap->storage[hash]) {
		if (hash < hashmap->size - 1) {
			hash++;
		} else {
			hash = 0;
		}
	}
	node = malloc(sizeof(HashNode));
	node->key = key;
	node->val = val;
	hashmap->storage[hash] = node;
}

HashNode * hash_get(HashMap *hashmap, int key)
{
	int hash;
	HashNode *node;
	
	hash = abs(key) % hashmap->size;
	while (node = hashmap->storage[hash]) {
		if (node->key == key) {
			return node;
		}
		if (hash < hashmap->size) {
			hash++;
		} else {
			hash = 0;
		}
	}
	return NULL;
}

int *towSum (int *nums, int numsSize; int target) 
{
	HashMap *hashmap;
	HashNode *node;
	int rest, i;
	
	hashmap = hash_create(numsSize * 2);
	
	for (i = 0; i < numsSize; i++) {
		rest = target - nums[i];
		node = hash_get(hashmap, rest);
		if (node) {
			int *result = malloc(sizeof(int) * 2);
			result[0] = node->val;
			result[1] = i;
			hash_destory(hashmap);
			return result;
		} else {
			hash_set(hashmap, nums[i], i);
		}
	}
	
	return NULL;
}