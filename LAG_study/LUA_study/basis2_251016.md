# buildLog
- program: **lua_basis_2** 
- from: **runoob** 
- status: **done** 

-----------------------------------------------------------------------------

### 循環

```lua
while(<condition>) do
    <statements>
end

for i=1, 10, 1 do   --  結尾值會在進入循環時確定
    <statements>
end

for k,v in table do
    <statements>
end

repeat              -- do while(! <condition>)
    <statements>
until(<condition>)
```

**關於 pairs() ipairs()** 
- pairs() 先遍歷數字索引 再遍歷標識索引
- ipairs() 僅遍歷數字索引

> 不存在continue 

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### 函數

支持特性
- 多返回值
- 可變參數

```lua

-- 多返回值
function func()
    return a, b
end
-- 多返回值不被接收的部分會被捨棄
-- exp : func(), func()   =>  (a, b), (a, b)
-- => a, a, b

-- 可變參數
function <func_name>(recv, ...)
    local args = {...}
    -- 創建一個表
    select("#", ...)
    -- 獲取參數數量
    select(n, ...)
    -- 從 n 開始到結束位置的參數 
    -- exp : select(2, 1, 2, 3, 4) => 2, 3, 4
end

```

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

> 邏輯運算符比較布爾值並返回原值且短路求值 因而可用於實現三目運算
> **!!! 這種寫法在 B = false 時會失效**
> - `<condition> and <TrueS> or <FalseS>`
> - - A and B : A=false ? A : B
> - - A or B  : A=true  ? A : B

-----------------------------------------------------------------------------
