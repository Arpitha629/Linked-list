#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// Node structure
struct node {
int data;
struct node *next;
};

// Insert at end
struct node* insert_end(struct node *start, int data) {
struct node *temp, *curr;

temp = (struct node*)malloc(sizeof(struct node));
temp-&gt;data = data;
temp-&gt;next = NULL;

if (start == NULL)
return temp;

curr = start;
while (curr-&gt;next != NULL)
curr = curr-&gt;next;

curr-&gt;next = temp;
return start;
}

// Display list

void display(struct node *start) {
struct node *curr = start;
while (curr != NULL) {
printf(&quot;%d -&gt; &quot;, curr-&gt;data);
curr = curr-&gt;next;
}
printf(&quot;NULL\n&quot;);
}

// Reverse SLL
struct node* reverse(struct node *start) {
struct node *prev = NULL, *curr = start, *temp = NULL;

while (curr != NULL) {
temp = curr-&gt;next; // store next
curr-&gt;next = prev; // reverse link
prev = curr; // move prev
curr = temp; // move curr
}
start = prev;
return start;
}

// -------- Main Program --------
int main() {
struct node *start = NULL;

start = insert_end(start, 10);
start = insert_end(start, 20);

start = insert_end(start, 30);
start = insert_end(start, 40);

printf(&quot;Original List:\n&quot;);
display(start);

start = reverse(start);

printf(&quot;Reversed List:\n&quot;);
display(start);

return 0;
}
