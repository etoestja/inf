<TeXmacs|1.0.7.15>

<style|generic>

<\body>
  <\with|language|russian>
    <\enumerate-numeric>
      <item><with|font-series|bold|\<#411\>\<#44B\>\<#441\>\<#442\>\<#440\>\<#43E\>\<#435\>
      \<#443\>\<#43C\>\<#43D\>\<#43E\>\<#436\>\<#435\>\<#43D\>\<#438\>\<#435\>.>

      \<#41F\>\<#443\>\<#441\>\<#442\>\<#44C\>
      <math|f<around*|(|a,b|)><above|=|def>ab>.
      \<#417\>\<#430\>\<#43C\>\<#435\>\<#442\>\<#438\>\<#43C\>,
      \<#447\>\<#442\>\<#43E\>\ 

      <math|f<around*|(|a,b|)><below|=|a\<vdots\>2><dfrac|a|2>b+<dfrac|a|2>b><strong|<math|\<vee\>>><math|f<around*|(|a,b|)><below|=|a
      mod 2 = 1><dfrac|a-1|2>b+<dfrac|a-1|2>b>,

      \<#433\>\<#434\>\<#435\> \<#434\>\<#435\>\<#43B\>\<#435\>\<#43D\>\<#438\>\<#435\>
      \<#446\>\<#435\>\<#43B\>\<#43E\>\<#447\>\<#438\>\<#441\>\<#43B\>\<#435\>\<#43D\>\<#43D\>\<#43E\>\<#435\>.\ 

      \<#41A\>\<#43E\>\<#434\> \<#43D\>\<#430\> C:

      <\cpp-code>
        int f(int a, int b)

        {

        \ \ \ \ int c;

        \ \ \ \ if(a == 0 \|\| b == 0) return(0);

        \ \ \ \ else

        \ \ \ \ {

        \ \ \ \ \ \ \ \ if(a % 2)

        \ \ \ \ \ \ \ \ {

        \ \ \ \ \ \ \ \ \ \ \ \ c = f((a - 1) / 2, b);

        \ \ \ \ \ \ \ \ \ \ \ \ return(c + c + b);

        \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ else

        \ \ \ \ \ \ \ \ {

        \ \ \ \ \ \ \ \ \ \ \ \ c = f(a / 2, b);

        \ \ \ \ \ \ \ \ \ \ \ \ return(c +<text|> c);

        \ \ \ \ \ \ \ \ }

        \ \ \ \ }

        }
      </cpp-code>

      \<#41D\>\<#430\> python:

      <\cpp-code>
        def f(a, b):

        \ if a == 0 or b == 0:

        \ \ return 0

        \ else:

        \ \ if a % 2 == 1:

        \ \ \ c = f((a - 1) / 2, b)

        \ \ \ return c + c + b

        \ \ else:

        \ \ \ c = f(a / 2, b)

        \ \ \ return c + c
      </cpp-code>

      <item><with|font-series|bold|\<#420\>\<#435\>\<#448\>\<#435\>\<#442\>\<#43E\>
      \<#42D\>\<#440\>\<#430\>\<#442\>\<#43E\>\<#441\>\<#444\>\<#435\>\<#43D\>\<#430\>>

      <\enumerate>
        <item><with|language|russian|<with|font|cyrillic|\<#414\>\<#43E\>\<#43A\>\<#430\>\<#437\>\<#430\>\<#442\>\<#435\>\<#43B\>\<#44C\>\<#441\>\<#442\>\<#432\>\<#43E\>
        \<#432\>\<#43E\>\<#437\>\<#43C\>\<#43E\>\<#436\>\<#43D\>\<#43E\>\<#441\>\<#442\>\<#438\>
        \<#437\>\<#430\>\<#43C\>\<#435\>\<#43D\>\<#44B\>
        2i<math|\<rightarrow\>i<rsup|2>>>>:

        \<#41F\>\<#443\>\<#441\>\<#442\>\<#44C\>
        <math|P(i)=>''<math|\<forall\>k\<in\>\<bbb-N\>>, k<math|\<geqslant\>2
        ><math|\<forall\>n\<in\>\<bbb-N\>\<cap\><around*|[|2;i|]>><math|
        >\<#43D\>\<#43E\>\<#432\>\<#44B\>\<#439\>
        \<#430\>\<#43B\>\<#433\>\<#43E\>\<#440\>\<#438\>\<#442\>\<#43C\>
        \<#432\><math|>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#443\>\<#43B\>
        \<#432\>\<#441\>\<#435\> \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\>
        \<#432\>\<#438\>\<#434\>\<#430\> <math|nk>''<verbatim|<strong|<em|<samp|>>>><math|>

        <\enumerate-numeric>
          <item>\<#414\>\<#43B\>\<#44F\> i=2
          (\<#43C\>\<#438\>\<#43D\>\<#438\>\<#43C\>\<#430\>\<#43B\>\<#44C\>\<#43D\>\<#43E\>\<#435\>)
          2i=i<math|<rsup|2>> <math|\<Rightarrow\>>\<#434\>\<#43E\>\<#43A\>\<#430\>\<#437\>\<#44B\>\<#432\>\<#430\>\<#435\>\<#43C\>\<#43E\>\<#435\>
          \<#432\>\<#435\>\<#440\>\<#43D\>\<#43E\>

          <item>\<#41F\>\<#443\>\<#441\>\<#442\>\<#44C\> <math|P(i)>.
          \<#414\>\<#43E\>\<#43A\>\<#430\>\<#436\>\<#435\>\<#43C\>,
          \<#447\>\<#442\>\<#43E\> <math|P(i<math|+>1)>:

          <math|P(i)<math|\<Rightarrow\>><math|\<forall\>k\<in\>\<bbb-N\>>,
          k<math|\<geqslant\>2 ><math|\<forall\>n\<in\>\<bbb-N\>\<cap\><around*|[|2;i|]>><math|
          >>\<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#443\>\<#442\>\<#44B\>
          \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\>
          \<#432\>\<#438\>\<#434\>\<#430\> nk<math| \<Rightarrow\>>
          \<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#443\>\<#442\>\<#44B\>
          \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\>
          \<#432\>\<#438\>\<#434\>\<#430\> <math|n(i+1)>,
          \<#433\>\<#434\>\<#435\> <math-up|<math|n><verbatim|<samp|<name|<math|\<in\>\<bbb-N\>\<cap\><around*|[|2;i|]>>>>>>.
          \<#422\>\<#43E\>\<#433\>\<#434\>\<#430\>
          \<#430\>\<#43B\>\<#433\>\<#43E\>\<#440\>\<#438\>\<#442\>\<#43C\>
          \<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#435\>\<#442\>
          \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\>
          \<#432\>\<#438\>\<#434\>\<#430\> <math|(i+1)(i+1)>, (i+2)(i+1)...,
          \<#442\>.\<#435\>. \<#431\>\<#443\>\<#434\>\<#443\>\<#442\>
          \<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#443\>\<#442\>\<#44B\>
          \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\> n(i+1),
          \<#433\>\<#434\>\<#435\> n<verbatim|<samp|<name|<math|\<in\>\<bbb-N\>,n\<geqslant\>i+1\<nosymbol\>\<Rightarrow\>>>>>\<#431\>\<#443\>\<#434\>\<#443\>\<#442\>
          \<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#43D\>\<#443\>\<#442\>\<#44B\>
          \<#432\>\<#441\>\<#435\> \<#447\>\<#438\>\<#441\>\<#43B\>\<#430\>
          \<#432\>\<#438\>\<#434\>\<#430\> <math|n(i+1)>,
          \<#433\>\<#434\>\<#435\> <math|n><name|<math|\<in\>\<bbb-N\>\<cap\><around*|(|<around*|[|2;i|]>\<cup\><around*|[|i+1;+\<infty\>|]>|)>>><math|\<box\>>

          <item>\<#41F\>\<#43E\> \<#430\>\<#43A\>\<#441\>\<#438\>\<#43E\>\<#43C\>\<#435\>
          \<#43E\>\<#431\> \<#438\>\<#43D\>\<#434\>\<#443\>\<#43A\>\<#446\>\<#438\>\<#438\>
          <math|\<forall\>i\<geqslant\>2 P<around*|(|i|)>>
        </enumerate-numeric>

        <item>\<#412\>\<#43D\>\<#443\>\<#442\>\<#440\>\<#435\>\<#43D\>\<#43D\>\<#438\>\<#439\>
        \<#446\>\<#438\>\<#43A\>\<#43B\> \<#441\>\<#43E\>\<#432\>\<#435\>\<#440\>\<#448\>\<#430\>\<#435\>\<#442\>
        <math|N-i<math|<rsup|2>>> \<#43E\>\<#43F\>\<#435\>\<#440\>\<#430\>\<#446\>\<#438\>\<#439\>
        (\<#43F\>\<#440\>\<#438\> <math|i\<less\><around*|\<lfloor\>|<sqrt|N>|\<rfloor\>>>,
        \<#43F\>\<#440\>\<#438\> \<#431\>\<#43E\>\<#43B\>\<#44C\>\<#448\>\<#438\>\<#445\>
        <math|i> \<#432\>\<#43D\>\<#443\>\<#442\>\<#440\>\<#435\>\<#43D\>\<#43D\>\<#438\>\<#439\>
        \<#446\>\<#438\>\<#43A\>\<#43B\> \<#437\>\<#430\>\<#43D\>\<#438\>\<#43C\>\<#430\>\<#435\>\<#442\>
        \<#43A\>\<#43E\>\<#43D\>\<#441\>\<#442\>\<#430\>\<#43D\>\<#442\>\<#43D\>\<#43E\>\<#435\>
        \<#432\>\<#440\>\<#435\>\<#43C\>\<#44F\>,
        \<#441\>\<#43B\>\<#435\>\<#434\>\<#43E\>\<#432\>\<#430\>\<#442\>\<#435\>\<#43B\>\<#44C\>\<#43D\>\<#43E\>,
        \<#43A\> \<#43E\>\<#431\>\<#449\>\<#435\>\<#43C\>\<#443\>
        \<#432\>\<#440\>\<#435\>\<#43C\>\<#435\>\<#43D\>\<#438\>
        \<#43F\>\<#440\>\<#438\>\<#431\>\<#430\>\<#432\>\<#43B\>\<#44F\>\<#435\>\<#442\>\<#441\>\<#44F\>
        <math| O(N-<math|<sqrt|N>>)>, \<#43D\>\<#435\>
        \<#443\>\<#447\>\<#438\>\<#442\>\<#44B\>\<#432\>\<#430\>\<#435\>\<#43C\>)
        <math|\<Rightarrow\>T<rsub|inner>\<sim\><below|<above|<big|sum>|<around*|\<lfloor\>|<sqrt|N>|\<rfloor\>>>|i=2><around*|(|N-i<rsup|2>|)>=>N<math|<around*|\<lfloor\>|<sqrt|N>|\<rfloor\>>-><math|<dfrac|<around*|\<lfloor\>|<sqrt|N>|\<rfloor\>><around*|(|<around*|\<lfloor\>|<sqrt|N>|\<rfloor\>>+1|)><around*|(|2<around*|\<lfloor\>|<sqrt|N>|\<rfloor\>>+1|)>|6>+1><math|<above|\<leqslant\>|m=<sqrt|N>>><math|m<rsup|2>m-<math|<dfrac|m<around*|(|m+1|)><around*|(|2m+1|)>|6>>+1\<leqslant\>m<rsup|3>\<Rightarrow\>
        T<rsub|inner>\<in\>O<around*|(|N<rsup|3/2>|)>>

        <item>\<#41D\>\<#430\> \<#43F\>\<#440\>\<#430\>\<#43A\>\<#442\>\<#438\>\<#43A\>\<#435\>
        \<#440\>\<#435\>\<#437\>\<#443\>\<#43B\>\<#44C\>\<#442\>\<#430\>\<#442\>
        \<#443\>\<#43B\>\<#443\>\<#447\>\<#448\>\<#438\>\<#442\>\<#441\>\<#44F\>,
        \<#442\>\<#430\>\<#43A\> \<#43A\>\<#430\>\<#43A\>
        \<#431\>\<#443\>\<#434\>\<#435\>\<#442\>
        \<#441\>\<#43E\>\<#432\>\<#435\>\<#440\>\<#448\>\<#430\>\<#442\>\<#44C\>\<#441\>\<#44F\>
        \<#437\>\<#430\>\<#432\>\<#435\>\<#434\>\<#43E\>\<#43C\>\<#43E\>
        \<#43C\>\<#435\>\<#43D\>\<#44C\>\<#448\>\<#435\>
        \<#43E\>\<#43F\>\<#435\>\<#440\>\<#430\>\<#446\>\<#438\>\<#439\>.

        <item>\<#41C\>\<#43E\>\<#436\>\<#435\>\<#442\>
        \<#432\>\<#43E\>\<#437\>\<#43D\>\<#438\>\<#43A\>\<#43D\>\<#443\>\<#442\>\<#44C\>
        \<#43F\>\<#440\>\<#43E\>\<#431\>\<#43B\>\<#435\>\<#43C\>\<#430\>
        \<#43F\>\<#435\>\<#440\>\<#435\>\<#43F\>\<#43E\>\<#43B\>\<#43D\>\<#435\>\<#43D\>\<#438\>\<#44F\>
        \<#43F\>\<#435\>\<#440\>\<#435\>\<#43C\>\<#435\>\<#43D\>\<#43D\>\<#43E\>\<#439\>
        j (\<#43D\>\<#430\>\<#43F\>\<#440\>\<#438\>\<#43C\>\<#435\>\<#440\>,
        2i \<#43E\>\<#43A\>\<#43E\>\<#43B\>\<#43E\>
        \<#43E\>\<#433\>\<#440\>\<#430\>\<#43D\>\<#438\>\<#447\>\<#435\>\<#43D\>\<#438\>\<#44F\>
        \<#442\>\<#438\>\<#43F\>\<#430\> int,
        \<#442\>\<#43E\>\<#433\>\<#434\>\<#430\> <math|i<rsup|2>>
        \<#442\>\<#43E\>\<#447\>\<#43D\>\<#43E\>
        \<#431\>\<#443\>\<#434\>\<#435\>\<#442\> \<#437\>\<#430\>
        \<#43F\>\<#440\>\<#435\>\<#434\>\<#435\>\<#43B\>\<#430\>\<#43C\>\<#438\>.
        \<#42D\>\<#442\>\<#43E\> \<#43F\>\<#440\>\<#438\>\<#432\>\<#435\>\<#434\>\<#435\>\<#442\>
        \<#43A\> \<#43E\>\<#448\>\<#438\>\<#431\>\<#43E\>\<#447\>\<#43D\>\<#43E\>\<#43C\>\<#443\>
        \<#432\>\<#44B\>\<#447\>\<#435\>\<#440\>\<#43A\>\<#438\>\<#432\>\<#430\>\<#43D\>\<#438\>\<#44E\>
        \<#447\>\<#438\>\<#441\>\<#435\>\<#43B\>.
      </enumerate>

      <item><with|font-series|bold|\<#418\>\<#43D\>\<#432\>\<#435\>\<#440\>\<#441\>\<#438\>\<#438\>>

      \;
    </enumerate-numeric>

    <with|font|cyrillic|>
  </with>
</body>

<\initial>
  <\collection>
    <associate|font|cyrillic>
    <associate|language|russian>
    <associate|page-type|letter>
    <associate|par-sep|0.2fn>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?>>
  </collection>
</references>