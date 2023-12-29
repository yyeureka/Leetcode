#include "head.h"

/*
Implement three stacks by single array.
You can assume the three stacks has the same size and big enough, you don't need to care about how to extend it if one of the stack is full.

Example
ThreeStacks(5)  // create 3 stacks with size 5 in single array. stack index from 0 to 2
push(0, 10) // push 10 in the 1st stack.
push(0, 11)
push(1, 20) // push 20 in the 2nd stack.
push(1, 21)
pop(0) // return 11
pop(1) // return 21
peek(1) // return 20
push(2, 30)  // push 30 in the 3rd stack.
pop(2) // return 30
isEmpty(2) // return true
isEmpty(0) // return false

����˼·�����临�� ��ȫ����������
�����ı����ǰ���������������ַ����������ʵ��ջ������buffer�е�ÿһ��Ԫ�أ������ܵ����Ǽ򵥵�int���ͣ�����һ�������еĽڵ㣬������ֵvalue��ջ����ջ�׷����֮ǰԪ������prev����ջ������ĺ���Ԫ������next��
�ڸ���ջ���ݽṹ�У�Ҫ��¼����ջ��ָ��stackPointer��Ҳ��������ջ�����ڵ�����������ͨ��������ջ���ڵ㣬�ܹ���prev�ҵ�����ջ��
���⻹Ҫ��indexUsed��¼���������е����õ�����������ʵҲ������һ��push��ʱ���������indexUsedλ�ô洢��

���������
���죺Ҫ��ʼ��stackPointerΪ3��-1,��ʾû��;indexUsed=0;bufferΪһ������Ϊ����ջ��С�����顣
push��Ҫ���½��new��buffer[indexUsed]��ͬʱ�޸ĸ�ջ��stackPointer��indexUsed������ע���޸ĵ�ǰջ�����prev��֮ǰջ������next������
peek��ֻ��Ҫ����buffer�ж�Ӧ��stackPointer���ɡ�
isEmpty��ֻ���ж�stackPointer�Ƿ�Ϊ-1��
pop��pop�Ĳ�����Ϊ���ӣ���Ϊ������ջ������ջ����һ��������β�ˣ�pop��ջ��֮�������п��ܴ��ڿն���������ն��ֺ���push��Ԫ�ء����ԣ���������ǣ���Ҫpop��Ԫ�ز�������β�ˣ���indexUsed-1��ʱ������������Ԫ�ء�����һ��Ҫע�⣬������ʱ��Ҫע���޸�������Ԫ��֮ǰ��֮�����prev��nextָ�룬ʹ��������Ȼ����ȷ�ģ���ʵ������ǽ����next�����á���Ϊ���ҵ�֮���㲢�޸�����prev���ڽ���ʱ��һ�ֺ�����������ջ���ڵ�պ�������β��Ԫ�صĺ�̽ڵ㣬��ʱ��Ҫ�����⴦���ڽ�����ɺ󣬾Ϳ���ɾ������β��Ԫ�أ����޸���Ӧ��stackPointer��indexUsed����ջ����next��
*/

class ThreeStacks {
public:
	class StackNode {
	public:
		int prev;
		int next;
		int value;

		StackNode(int p, int v, int n) {
			value = v;
			prev = p;
			next = n;
		}
	};

	int stackSize;
	int indexUsed;
	vector<int> stackPointer;
	vector<StackNode *> buffer;

	/*
	* @param size: An integer
	*/ThreeStacks(int size) {
		stackSize = size;
		stackPointer = vector<int>(3, -1);
		indexUsed = 0;
		buffer = vector<StackNode *>(stackSize * 3);
	}

	/*
	* @param stackNum: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void push(int stackNum, int value) {
		int lastIndex = stackPointer[stackNum];
		stackPointer[stackNum] = indexUsed;
		indexUsed++;
		buffer[stackPointer[stackNum]] = new StackNode(lastIndex, value, -1);
		if (lastIndex != -1) {
			buffer[lastIndex]->next = stackPointer[stackNum];
		}
	}

	/*
	* @param stackNum: An integer
	* @return: the top element
	*/
	int pop(int stackNum) {
		int value = buffer[stackPointer[stackNum]]->value;
		int lastIndex = stackPointer[stackNum];
		if (lastIndex != indexUsed - 1)
			swap(lastIndex, indexUsed - 1, stackNum);

		stackPointer[stackNum] = buffer[stackPointer[stackNum]]->prev;
		if (stackPointer[stackNum] != -1)
			buffer[stackPointer[stackNum]]->next = -1;

		buffer[indexUsed - 1] = NULL;
		indexUsed--;
		return value;
	}

	/*
	* @param stackNum: An integer
	* @return: the top element
	*/
	int peek(int stackNum) {
		return buffer[stackPointer[stackNum]]->value;
	}

	/*
	* @param stackNum: An integer
	* @return: true if the stack is empty else false
	*/
	bool isEmpty(int stackNum) {
		return stackPointer[stackNum] == -1;
	}

	void swap(int lastIndex, int topIndex, int stackNum) {
		if (buffer[lastIndex]->prev == topIndex) {
			int tmp = buffer[lastIndex]->value;
			buffer[lastIndex]->value = buffer[topIndex]->value;
			buffer[topIndex]->value = tmp;
			int tp = buffer[topIndex]->prev;
			if (tp != -1) {
				buffer[tp]->next = lastIndex;
			}
			buffer[lastIndex]->prev = tp;
			buffer[lastIndex]->next = topIndex;
			buffer[topIndex]->prev = lastIndex;
			buffer[topIndex]->next = -1;
			stackPointer[stackNum] = topIndex;
			return;
		}

		int lp = buffer[lastIndex]->prev;
		if (lp != -1)
			buffer[lp]->next = topIndex;

		int tp = buffer[topIndex]->prev;
		if (tp != -1)
			buffer[tp]->next = lastIndex;

		int tn = buffer[topIndex]->next;
		if (tn != -1)
			buffer[tn]->prev = lastIndex;
		else {
			for (int i = 0; i < 3; ++i)
				if (stackPointer[i] == topIndex)
					stackPointer[i] = lastIndex;
		}

		StackNode *tmp = buffer[lastIndex];
		buffer[lastIndex] = buffer[topIndex];
		buffer[topIndex] = tmp;
		stackPointer[stackNum] = topIndex;
	}
};