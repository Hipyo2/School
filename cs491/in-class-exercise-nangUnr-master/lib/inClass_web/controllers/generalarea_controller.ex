defmodule InClassWeb.GeneralareaController do
  use InClassWeb, :controller

  alias InClass.Company
  alias InClass.Company.Generalarea

  def index(conn, _params) do
    generalareas = Company.list_generalareas()
    render(conn, "index.html", generalareas: generalareas)
  end

  def new(conn, _params) do
    changeset = Company.change_generalarea(%Generalarea{})
    render(conn, "new.html", changeset: changeset)
  end

  def create(conn, %{"generalarea" => generalarea_params}) do
    case Company.create_generalarea(generalarea_params) do
      {:ok, generalarea} ->
        conn
        |> put_flash(:info, "Generalarea created successfully.")
        |> redirect(to: Routes.generalarea_path(conn, :show, generalarea))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    generalarea = Company.get_generalarea!(id)
    render(conn, "show.html", generalarea: generalarea)
  end

  def edit(conn, %{"id" => id}) do
    generalarea = Company.get_generalarea!(id)
    changeset = Company.change_generalarea(generalarea)
    render(conn, "edit.html", generalarea: generalarea, changeset: changeset)
  end

  def update(conn, %{"id" => id, "generalarea" => generalarea_params}) do
    generalarea = Company.get_generalarea!(id)

    case Company.update_generalarea(generalarea, generalarea_params) do
      {:ok, generalarea} ->
        conn
        |> put_flash(:info, "Generalarea updated successfully.")
        |> redirect(to: Routes.generalarea_path(conn, :show, generalarea))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", generalarea: generalarea, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    generalarea = Company.get_generalarea!(id)
    {:ok, _generalarea} = Company.delete_generalarea(generalarea)

    conn
    |> put_flash(:info, "Generalarea deleted successfully.")
    |> redirect(to: Routes.generalarea_path(conn, :index))
  end
end
