using ll = long long;

class Bank {
public:
    vector<ll> balance;

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool is_valid(int idx) {
        return idx >= 0 && idx < balance.size();
    }

    bool transfer(int ac1, int ac2, long long money) {
        ac1--, ac2--;
        if (!is_valid(ac1) || !is_valid(ac2)) {
            return false;
        }
        if (balance[ac1] < money) {
            return false;
        }
        balance[ac1] -= money;
        balance[ac2] += money;
        return true;
    }
    
    bool deposit(int ac, long long money) {
        ac--;
        if (!is_valid(ac)) {
            return false;
        }   
        balance[ac] += money;
        return true;
    }
    
    bool withdraw(int ac, long long money) {
        ac--;
        if (!is_valid(ac)) {
            return false;
        }   
        if (balance[ac] < money) {
            return false;
        }
        balance[ac] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */