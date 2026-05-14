use std::{collections::HashMap, fmt::Error, ops::Add};

impl Solution {
    pub fn is_good(nums: Vec<i32>) -> bool {
        let mut mp: HashMap<i32, i32> = HashMap::new();

        let n = nums.len();

        if n == 1 {
            return false;
        }
        for val in nums.into_iter() {
            let res = mp.get(&val);
            match res {
                Some(count) => mp.insert(val, count + 1),
                None => mp.insert(val, 1)
            };
        }

        for i in 1..n {
            let res = mp.get(&(i as i32));

            match res {
                Some(val) => {
                    if i == n - 1 {
                        if *val != 2 {
                            return false;
                        }
                    } else {
                        if *val != 1 {
                            return false;
                        }
                    }
                },
                None => {
                    return false;
                }
            }
            
        }
        return true;
    }
}
