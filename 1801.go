type Item struct {
	price     int
	amount    int
	orderType int
}

type PriorityQueue []Item

func (pq PriorityQueue) Len() int {
	return len(pq)
}
func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].orderType == 0 {
		return pq[i].price > pq[j].price
	} else {
		return pq[i].price < pq[j].price
	}
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(v interface{}) {
	*pq = append(*pq, v.(Item))
}
func (pq *PriorityQueue) Pop() interface{} {
	a := *pq
	v := a[len(a)-1]
	*pq = a[:len(a)-1]
	return v
}

func getNumberOfBacklogOrders(orders [][]int) (ans int) {
	buys, sells := PriorityQueue{}, PriorityQueue{}
	ret := 0
	for _, order := range orders {
		price, amount, orderType := order[0], order[1], order[2]
		if orderType == 0 {
			for amount > 0 && len(sells) > 0 && sells[0].price <= price {
				if sells[0].amount > amount {
					sells[0].amount -= amount
					amount = 0
					break
				}
				amount -= heap.Pop(&sells).(Item).amount
			}
			if amount > 0 {
				heap.Push(&buys, Item{price, amount, orderType})
			}
		} else {
			for amount > 0 && len(buys) > 0 && buys[0].price >= price {
				if buys[0].amount > amount {
					buys[0].amount -= amount
					amount = 0
					break
				}
				amount -= heap.Pop(&buys).(Item).amount
			}
			if amount > 0 {
				heap.Push(&sells, Item{price, amount, orderType})
			}
		}
	}
	for i := 0; i < len(buys); i++ {
		ret = (ret + buys[i].amount) % (1e9 + 7)
	}
	for i := 0; i < len(sells); i++ {
		ret = (ret + sells[i].amount) % (1e9 + 7)
	}
	return ret
}
