local pac = {}

function pac._cmp(e1, e2)
    return e1<=e2
end

function pac._swap(n1, n2, t)
    t[n1], t[n2] = t[n2], t[n1]
end

function pac.insertionSort( table, length, cmp) 
    local length  = length or #table
    local cmp     = cmp    or pac._cmp
    local node_select, node_cmp

    for node_select=2, length, 1 do
        node_cmp = node_select-1
        while node_cmp ~= 0 do
            if cmp( table[node_cmp], table[node_cmp+1] ) then
                break
            end
            pac._swap(node_cmp, node_cmp+1, table)
            -- print("swap", node_cmp, node_cmp+1)
            node_cmp = node_cmp - 1
        end
    end
    return table
end


---[[ TEST ME
print( "test insertion sort" )

pac.iS = pac.insertionSort

test_table = {2,3,1,3,2,4,3}
pac.iS(test_table)
for k,v in ipairs(test_table) do
    print (v )
end
--]]

return pac
