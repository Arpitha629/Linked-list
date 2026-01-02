#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// Node structure
struct node {
int data;
struct node *next;
};

// Insert at beginning
struct node* insert_begin(struct node *start, int data) {
struct node *temp, *curr;

temp = (struct node*)malloc(sizeof(struct node));
temp-&gt;data = data;

if (start == NULL) {
temp-&gt;next = temp;
start = temp;
return start;
}

curr = start;
while (curr-&gt;next != start)
curr = curr-&gt;next;

temp-&gt;next = start;
curr-&gt;next = temp;
start = temp;

return start;
}

// Insert at end
struct node* insert_end(struct node *start, int data) {
struct node *temp, *curr;

temp = (struct node*)malloc(sizeof(struct node));
temp-&gt;data = data;

if (start == NULL) {
temp-&gt;next = temp;
start = temp;
return start;
}

curr = start;
while (curr-&gt;next != start)
curr = curr-&gt;next;

curr-&gt;next = temp;
temp-&gt;next = start;

return start;
}

// Delete a node
struct node* delete(struct node *start, int key) {

struct node *curr = start, *prev = NULL;

if (start == NULL)
return start;

// Single node case
if (start-&gt;data == key &amp;&amp; start-&gt;next == start) {
free(start);
return NULL;
}

// If first node is to be deleted
if (start-&gt;data == key) {
curr = start;
while (curr-&gt;next != start)
curr = curr-&gt;next;

curr-&gt;next = start-&gt;next;
free(start);
start = curr-&gt;next;
return start;
}

prev = start;
curr = start-&gt;next;

while (curr != start &amp;&amp; curr-&gt;data != key) {
prev = curr;
curr = curr-&gt;next;

}

if (curr == start) {
printf(&quot;Element not found\n&quot;);
return start;
