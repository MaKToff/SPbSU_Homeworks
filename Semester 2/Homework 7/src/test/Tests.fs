﻿(*
Homework 7 (13.04.2015)
Tests for tasks 40 - 41.

Author: Mikhail Kita, group 171
*)

module Tests

open NUnit.Framework
open Workflow

// Tests for the 40th task
[<TestCase(5,  Result = 0)>]
[<TestCase(1,  Result = 0)>]
[<TestCase(3,  Result = 1)>]
[<TestCase(15, Result = 10)>]
let ``Test for 40th task #1: ring of residues modulo`` (n) =
    ring n {
        let! a = 2 * 3
        let! b = 4
        return a + b
    }

[<Test>]
let ``Test for 40th task #2: overflow`` () =
    let example =
        ring 7 {
            let! a = 2 * 3
            let! b = 9999999 * 7777778
            return a * pown b 4
        }
    Assert.AreEqual(5, example)

[<TestCase(9,  Result = 8)>]
[<TestCase(13, Result = 3)>]
let ``Test for 40th task #3: return of negative number`` (n) =
    ring n {
        let! a = -7 + (-3)
        return a
    }


// Tests for the 41st task
[<Test>]
let ``Test for 41st task #1: filter`` () =
    let tree = 
        Node (Node(Node(Null, 1, Null), 2, Null), 3, Node(Null, 4, Null))
    let t = filter (fun x -> x % 2 = 1) Null tree
    Assert.AreEqual(Node (Node (Null, 1, Null), 3, Null), t) 

[<Test>]
let ``Test for 41st task #2: map`` () =
    let tree = Node (Node(Null, 1, Null), 2, Node(Null, 4, Null))
    let t = map (fun x -> x * 2) Null tree
    Assert.AreEqual(Node (Node(Null, 2, Null), 4, Node(Null, 8, Null)), t)

[<Test>]
let ``Test for 41st task #3.1: fold - minimum node`` () =
    let tree = 
        Node (Node(Node(Null, 1, Null), 1, Null), 2, Node(Null, 3, Null))
    let minElem arg1 arg2 =
        match arg1 with
        | None       -> Some (arg2)
        | Some value -> Some (min value arg2)
    Assert.AreEqual(Some 1, fold minElem None tree)

[<TestCase([|2; 1; 3; 1;|], Result = 7)>]
[<TestCase([|5; 3; 7; 2; 4; 6; 8; 1;|], Result = 36)>]
let ``Test for 41st task #3.2: fold - sum of all nodes`` (values : int array) =
    let mutable tree = Null
    for t in values do
        tree <- insert t tree
    fold (+) 0 tree

[<Test>]
let ``Test for 41st task #4: TreeBuilder.Combine`` () =
    let tree = Node (Null, 3, Null)
    let concat = 
        TreeBuilder((+), 0) {
            return tree
            return! 1
            let temp = map (fun x -> x + 1) Null tree
            return temp
        }
    Assert.AreEqual(Node (Node(Null, 1, Node(Null, 4, Null)), 3, Null), concat)