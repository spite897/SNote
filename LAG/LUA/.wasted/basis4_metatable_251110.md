# buildLog
- program: **lua_basis_4** 
- from: **runoob** 
- status: **done** 

-----------------------------------------------------------------------------

### Metatable

元表作用是改變表的行爲。
`表` 與 `其元表` 類似與 `實例` 與 `類` 的關係。

- **setmetatable( t, mt )** : 設置mt爲t的元表 返回t
- getmetatable( t )     : 返回t的元表

> 表只有一個元表
> 元表不能嵌套 即元表不能有元表
> 雙下劃線__metatable 屬性儲存元表地址

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- **關於元表的鍵值**

*以下敘述相對 表t 及 其元表mt*

1. 雙下劃線__index

通過鍵k訪問t時，如果t沒有對於值，則會返回__index[k]或__index( t, k )。（對應爲表與方法）

```
t.k 
=> t.k~=nil ? t.k ; ( mt.__index.k or mt.__index( t, k ) )
```

2. 雙下劃線__newindex

給t的空鍵k賦值時，會改爲 mt.__newindex[k]=v 或 mt.__newindex(t, k, v)。（對應表與方法時）

```
t[k] = v
=> if t[k] ~= nil   t[k] = v
else                ( mt.__newindex[k] = v) or ( mt.__newindex(t, k, v) )
```

3. 運算符重構

__add, __sub, __mul, __div, __mod, __pow

|          |      |
| -        | -    |
| __unm    | 取負 |
| __concat | ..   |
| __eq     | ==   |
| __lt     | <    |
| __le     | <=   |

> 其他關係運算符會轉化爲上三種
> 在函數中修改表是全局的，爲了穩定性請在方法中創建複製並返回。

4. 雙下劃線__call

調用t時，改爲mt.__call(<arg>)。

5.雙下劃線__tostring

-----------------------------------------------------------------------------
