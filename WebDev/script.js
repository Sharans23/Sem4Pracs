// Accordion functionality
const accordionItems = document.querySelectorAll(".accordion-item");

accordionItems.forEach((item) => {
  const header = item.querySelector(".accordion-header");
  const content = item.querySelector(".accordion-content");
  const icon = header.querySelector(".accordion-icon");

  header.addEventListener("click", () => {
    content.style.display = content.style.display === "none" ? "block" : "none";
    icon.textContent = content.style.display === "none" ? "&#9654;" : "&#9660;";
  });
});
