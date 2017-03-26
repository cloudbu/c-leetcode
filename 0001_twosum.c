/**
 * ����һ�����������һ��ֵtarget���������±�i��j��ʹ��a[i] + a[j] = target�������±�
 *
 */
 
/**
 * ʹ�ù�ϣ�����ϼ�¼ÿ��Ԫ�ض�Ӧ���±꣬��Ȼ�����target-a[i]�����ҵ��˾��У����Ҳ�����û��
 * ʹ��C���Ե�һ���ô���������ֶ�ʵ�ֹ�ϣ�������û���ֳɵĽӿڿ���ʹ��
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
 * ������ϣ��
 */
HashMap * hash_create(int size) 
{
	HashMap *hashmap = malloc(sizeof(HashMap));
	hashmap->size = size;
	hashmap->storage = calloc(size, sizeof(HashNode *));
	return hashmap;
}

/**
 * ɾ����ϣ��
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
	
	/* Ϊʲô���ÿ��ǹ�ϣ��ͻ����� */
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