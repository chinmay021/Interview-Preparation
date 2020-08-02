bool checkRedundancy(string &str)
{
    stack<char> st;
    for (auto &ch : str)
    {
        if (ch == ')')
        {

            bool flag = true;

            while (st.top() != '(')
            {
                if (st.top() == '+' || st.top() == '-' ||
                    st.top() == '*' || st.top() == '/')
                    flag = false;

                st.pop();
            }
            st.pop();
            if (flag == true)
                return true;
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}