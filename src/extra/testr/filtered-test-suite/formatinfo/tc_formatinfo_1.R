expected <- eval(parse(text="c(10L, 8L, 0L)"));         
test(id=0, code={         
argv <- eval(parse(text="list(c(0.099999994, 0.2), 7L, 0L)"));         
.Internal(format.info(argv[[1]], argv[[2]], argv[[3]]));         
}, o=expected);         

