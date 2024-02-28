#include "splashkit.h"

#include <functional>
using namespace std;

typedef struct node_data *node;

struct linked_list
{
    node first;
    node last;
};

struct node_data
{
    int data;
    node next;
    node prev;
    linked_list *in_list;
};

void initialise_list(linked_list &list)
{
    list.first = nullptr;
    list.last = nullptr;
}

bool list_is_empty(const linked_list &list)
{
    return list.first == nullptr;
}

node new_node(int value, linked_list &list, node prev, node next)
{
    node result;

    result = new node_data();

    result->data = value;
    result->prev = prev;
    result->next = next;
    result->in_list = &list;

    return result;
}

void add_to_end(linked_list &list, int value)
{
    node added_node;

    added_node = new_node(value, list, list.last, nullptr);

    if (not list_is_empty(list))
    {
        list.last->next = added_node;
        list.last = added_node;
    }
    else
    {
        list.first = added_node;
        list.last = added_node;
    }
}

void add_to_start(linked_list &list, int value)
{
    node added_node = new_node(value, list, nullptr, list.first);

    if (!list_is_empty(list))
    {
        list.first->prev = added_node;
        list.first = added_node;
    }
    else
    {
        list.first = added_node;
        list.last = added_node;
    }
}

node find_first(const linked_list &list, int value)
{
    node current;

    current = list.first;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current;
        }

        current = current->next;
    }
    return nullptr;
}

void delete_node(node current)
{
    linked_list *list;
    node before, after;

    list = current->in_list;
    before = current->prev;
    after = current->next;

    if (before != nullptr)
    {
        before->next = current->next;
    }
    else
    {
        list->first = after;
    }

    if (after != nullptr)
    {
        after->prev = current->prev;
    }
    else
    {
        list->last = before;
    }

    current->prev = nullptr;
    current->next = nullptr;

    delete current;
}

void print_node(node current)
{
    write(" -> " + to_string(current->data));
}

void print_all(const linked_list &list)
{
    node current;

    current = list.first;

    while (current != nullptr)
    {
        print_node(current);
        current = current->next;
    }
    write_line(".");
}

void reverse_print_all(const linked_list &list)
{
    node current = list.last;

    while (current != nullptr)
    {
        print_node(current);
        current = current->prev;
    }
    write_line(".");
}

typedef std::function<void(node)> visitor;

void for_each(const linked_list &list, visitor fn)
{
    node current;
    current = list.first;

    while (current != nullptr)
    {
        fn(current);
        current = current->next;
    }
}

void reverse_for_each(const linked_list &list, visitor fn)
{
    node current = list.last;

    while (current != nullptr)
    {
        fn(current);
        current = current->prev;
    }
}

void reverse_print_all_with_visitor(const linked_list &list)
{
    reverse_for_each(list, print_node);
    write_line(".");
}

void print_with_visitor(const linked_list &list)
{
    for_each(list, print_node);
    write_line(".");
}

int sum(const linked_list &list)
{
    int result = 0;

    for_each(list, [&](node current)
             { result += current->data; });

    return result;
}

void insert_after(node selected_node, int value)
{
    linked_list *list = selected_node->in_list;
    node new_node_ptr = new_node(value, *list, selected_node, selected_node->next);

    if (selected_node->next != nullptr)
    {
        selected_node->next->prev = new_node_ptr;
    }
    else
    {
        list->last = new_node_ptr;
    }
    selected_node->next = new_node_ptr;
}

int length(const linked_list &list)
{
    int count = 0;
    for_each(list, [&](node current)
             { count++; });
    return count;
}

int main()
{
    linked_list my_list;

    initialise_list(my_list);

    write_line("\nTEST: Add to end");
    add_to_end(my_list, 10);
    add_to_end(my_list, 20);
    add_to_end(my_list, 30);
    print_all(my_list);

    write_line("\nTEST: Add to start");
    add_to_start(my_list, 5);
    add_to_start(my_list, 15);
    add_to_start(my_list, 25);
    print_all(my_list);

    write_line("\nTest: Reverse print all");
    reverse_print_all(my_list);

    write_line("\nTest: Insert After");
    node node_to_insert_after = find_first(my_list, 15);
    insert_after(node_to_insert_after, 17);
    print_all(my_list);

    write_line("\nTest: Reverse print all with visitor");
    reverse_print_all_with_visitor(my_list);

    write_line("\nTEST: Sum");
    write("Sum is: ");
    write_line(sum(my_list));

    write_line("\nTEST: Length");
    write("Length is: ");
    write_line(length(my_list));

    node found;

    // Test find and delete...
    write_line(" ");
    found = find_first(my_list, 20);
    delete_node(found);
    print_all(my_list);

    // Delete start and end as well...
    found = find_first(my_list, 10);
    delete_node(found);
    print_with_visitor(my_list);

    found = find_first(my_list, 30);
    delete_node(found);
    print_all(my_list);

    // Add a new
    add_to_end(my_list, 40);
    print_all(my_list);

    return 0;
}