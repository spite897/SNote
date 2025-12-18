module = {}

module.var1 = "var of 1"
module.var2 = "var of 2"

function module.f1()
    io.write("Hello Globe\n")
end

local function f2()
    print("Hello Local\n")
end

function module.f3()
    f2()
end

return module
